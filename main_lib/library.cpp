#include "library.h"

namespace bigNum {

    bignum::bignum() {
        number = "";
        sign = false;
        real_size = 0;
    }

    bignum::bignum(int x) {
        if (x < 0) {
            sign = true;
            x *= -1;
        } else sign = false;
        number = std::to_string(x);
        real_size = static_cast<int>(number.length());
    }

    bignum::bignum(long long x) {
        if (x < 0) {
            sign = true;
            x *= -1;
        } else sign = false;
        number = std::to_string(x);
        real_size = static_cast<int>(number.length());
    }

    bignum::bignum(std::string x) {
        if (x[0] == '-') {
            sign = true;
            number = x.erase(0, 1);
        } else {
            sign = false;
            number = x;
        }
        real_size = static_cast<int>(number.find('.'));


        if (number.find_first_not_of("0123456789") != real_size || number.find_last_not_of("0123456789") != real_size)
            throw std::runtime_error(number + " it's not a number!");

        if (real_size == std::string::npos) real_size = static_cast<int>(number.length());
        else {
            for (int i = real_size; i < number.length(); i++) {
                number[i] = number[i + 1];
            }
            number.pop_back();
        }
    }

    bool operator>(const bigNum::bignum &a, const bigNum::bignum &b) {
        if (a.sign != b.sign) return !a.sign;
        if (a.real_size != b.real_size) return (a.real_size < b.real_size) == a.sign;
        for (int i = 0; i < std::max(a.number.length(), b.number.length()); i++) {
            char a_digit = '0';
            char b_digit = '0';
            if (i < a.number.length()) a_digit = a.number[i];
            if (i < b.number.length()) b_digit = b.number[i];
            if (a_digit != b_digit) return (a.number[i] < b.number[i]) == a.sign;
        }
        return false;
    }

    bool operator<(const bigNum::bignum &a, const bigNum::bignum &b) {
        return b > a;
    }

    bool operator>=(const bigNum::bignum &a, const bigNum::bignum &b) {
        return !(a < b);
    }

    bool operator<=(const bigNum::bignum &a, const bigNum::bignum &b) {
        return !(a > b);
    }

    bool operator==(const bigNum::bignum &a, const bigNum::bignum &b) {
        return !(a < b) && !(a > b);
    }
}

bigNum::bignum operator ""_bn(const char *str) {
    return bigNum::bignum(str);
}

bigNum::bignum operator-(const bigNum::bignum &a) {
    bigNum::bignum x = a;
    x.sign = !x.sign;
    return x;
}


#include "library.h"

namespace bigNum {
    bignum bignum::usub(const bignum &a, const bignum &b) {
        bigNum::bignum x = bignum();
        int a_from_dot = static_cast<int>(a.number.length()) - a.real_size;
        int b_after_zero = static_cast<int>(b.number.length()) - b.real_size;
        int after_zero = std::max(a_from_dot, b_after_zero);
        int mind = 0;
        for (int i = after_zero - 1; i >= 0; i--) {
            int res = -mind;
            if (i < a_from_dot) {
                res += a.number[a.real_size + i] - '0';
            }
            if (i < b_after_zero) {
                res -= b.number[b.real_size + i] - '0';
            }
            if (res < 0) {
                mind = 1;
                res += 10;
            } else mind = 0;
            x.number += static_cast<char>(res + '0');
        }
        x.real_size = std::max(a.real_size, b.real_size);
        for (int i = 0; i < x.real_size; i++) {
            int res = -mind;
            if (i < a.real_size) {
                res += a.number[a.real_size - i - 1] - '0';
            }
            if (i < b.real_size) {
                res -= b.number[b.real_size - i - 1] - '0';
            }
            if (res < 0) {
                mind = 1;
                res += 10;
            } else mind = 0;
            x.number += static_cast<char>(res + '0');
        }
        while (x.number.back() == '0' && x.real_size > 1) {
            x.real_size--;
            x.number.pop_back();
        }
        x.number = std::string(x.number.rbegin(), x.number.rend());
        while (x.number.back() == '0' && x.number.size() > 1) {
            x.number.pop_back();
        }
        x.real_size = std::min(x.real_size, static_cast<int>(x.number.length()));

        return x;
    }
    bignum bignum::sub(const bignum &a, const bignum &b) {
        if (a.sign != b.sign) {
            bignum x = uadd(a, b);
            x.sign = a.sign;
            return x;
        }
        if (a.sign) {
            if (a > -b) {
                bignum x = usub(a, b);
                x.sign = true;
                return x;
            }
            bignum x = usub(b, a);
            x.sign = false;
            return x;
        }
        if (b > -a) {
            bignum x = usub(a, b);
            x.sign = false;
            return x;
        }
        bignum x = usub(b, a);
        x.sign = true;
        return x;
    }
}
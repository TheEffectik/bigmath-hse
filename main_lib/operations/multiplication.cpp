#include "library.h"

namespace bigNum {
    bignum bignum::mul(const bignum &a, const bignum &b) {
        bigNum::bignum x = bignum();
        x.sign = (a.sign != b.sign);
        x.real_size = static_cast<int>(a.number.length()) + static_cast<int>(b.number.length());
        std::vector<int> res(x.real_size);
        for (int i = 0; i < a.number.length(); i++) {
            for (int j = 0; j < b.number.length(); j++) {
                res[i + j] += (a.number[a.number.length() - i - 1] - '0') * (b.number[b.number.length() - j - 1] - '0');
            }
        }
        for (int i = 0; i < x.real_size; i++) {
            res[i + 1] += res[i] / 10;
            x.number += static_cast<char> (res[i] % 10 + '0');
        }
        x.real_size = static_cast<int>(x.number.length()) - (static_cast<int>(a.number.length()) - a.real_size) -
                      (static_cast<int>(b.number.length()) - b.real_size);
        while (x.number.back() == '0' && x.real_size > 1) {
            x.real_size--;
            x.number.pop_back();
        }
        x.number = std::string(x.number.rbegin(), x.number.rend());
        while (x.number.back() == '0' && x.number.size() != x.real_size ) {
            x.number.pop_back();
        }
        x.real_size = std::min(x.real_size, static_cast<int>(x.number.length()));
        return x;
    }
}
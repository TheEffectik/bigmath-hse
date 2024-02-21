#include<iostream>
#include<string>
#include "library.h"

namespace bigNum {
    bignum bignum::udiv(const bignum &a, const bignum &b) {
        int mind = 0;
        bignum x = bignum();
        x.real_size = a.real_size;
        x.number = a.number;
        for (int i = 0; i < a.real_size; i++) {
            mind = mind * 10 + x.number[i] - '0';
            x.number[i] = static_cast<char>(mind / (b.number[0] - '0') + '0');
            mind %= b.number[0] - '0';
        }
        x.number = std::string(x.number.rbegin(), x.number.rend());
        return x;
    }
}
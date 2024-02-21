#include<iostream>
#include<string>
#include "library.h"

namespace bigNum{
    bignum bignum::uadd(const bignum& a, const bignum& b){
        bigNum::bignum x = bignum();
        int a_from_dot = static_cast<int>(a.number.length()) - a.real_size;
        int b_after_zero = static_cast<int>(b.number.length()) - b.real_size;
        int after_zero = std::max(a_from_dot, b_after_zero);
        int mind = 0;
        for(int i = after_zero - 1; i >= 0; i--){
            if(i < a_from_dot){
                mind += a.number[a.real_size + i] - '0';
            }
            if(i < b_after_zero){
                mind += b.number[b.real_size + i] - '0';
            }
            x.number += static_cast<char>(mind % 10 + '0');
            mind /= 10;
        }
        x.real_size = std::max(a.real_size, b.real_size);
        for(int i = 0; i < x.real_size; i++){
            if(i < a.real_size){
                mind += a.number[a.real_size - i - 1] - '0';
            }
            if(i < b.real_size){
                mind += b.number[b.real_size - i - 1] - '0';
            }
            x.number += static_cast<char>(mind % 10 + '0');
            mind /= 10;
        }
        if(mind) {
            x.number += static_cast<char>(mind + '0');
            x.real_size += 1;
        }
        x.number = std::string(x.number.rbegin(), x.number.rend());
        return x;
    }
}

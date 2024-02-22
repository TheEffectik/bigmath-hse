#include "library.h"

namespace bigNum {
    bignum bignum::div(const bignum &a, const bignum &b, int precision = 0) {
        bignum x = bignum();
        x.sign = (a.sign != b.sign);
        if (b == 0) throw std::runtime_error("Division by zero!");
        if (a == 0) return x;

        int a_from_dot = static_cast<int>(a.number.length()) - a.real_size;
        int b_after_zero = static_cast<int>(b.number.length()) - b.real_size;
        a_from_dot -= b_after_zero + precision;

        bignum a2 = a;
        for(;a_from_dot < 0;a_from_dot++){
            a2.number += '0';
        }
        a2.sign = false;
        bignum b2 = b;
        b2.real_size = b2.number.length();
        b2.sign = false;

        bignum ost = bignum();
        ost.real_size = b.number.length();
        int i = 0;

        while(i < a2.number.length()){
            if(ost.number.length()) {
                if (ost == 0) {
                    ost.number = "";
                    ost.real_size = 0;
                }
                ost.number += a.number[i++];
                ost.real_size++;
            }
            else{
                for(;i < a2.number.length() && i < b2.number.length();i++){
                    if(ost.number.length() + (a.number[i] - '0')) {
                        ost.number += a.number[i];
                        x.real_size++;
                    }
                }
            }
            int l = 0;
            int r = 10;
            while (r - l > 1){
                int m = (r + l) / 2;
                if(b2 * m <= ost){
                    l = m;
                } else {
                    r = m;
                }
            }
            if(x.number.length() + l) {
                x.number += static_cast<char>(l + '0');
                ost = ost - b2 * l;
            }
        }
        if(x.number == ""){
            x.number = "0";
        }
        x.real_size = x.number.length() - precision;
        return x;
    }
}
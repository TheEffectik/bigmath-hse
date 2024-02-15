#include<iostream>
#include<string>
#include "library.h"

bignum::bignum()
{
    number = "0";
    sign = false;
    real_size = 0;
}

bignum::bignum(int x) {
    if(x < 0) {
        sign = true;
        x *= -1;
    } else sign = false;
    number = std::to_string(x);
    real_size = number.length();
}

bignum::bignum(float x) {
    if(x < 0) {
        sign = true;
        x *= -1;
    } else sign = false;

    number = std::to_string(x);
    real_size = number.find('.');
}

bignum::bignum(double x) {
    if(x < 0) {
        sign = true;
        x *= -1;
    } else sign = false;

    number = std::to_string(x);
    real_size = number.find('.');
}
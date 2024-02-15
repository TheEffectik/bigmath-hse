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

bignum::bignum(long long x) {
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

bignum::bignum(std::string x) {
    if(x[0] == '-') {
        sign = true;
        number = x.erase(0, 1);
    } else {
        sign = false;
        number = x;
    }
    real_size = number.find('.');

    if (number.find_first_not_of("0123456789") != real_size || number.find_last_not_of("0123456789") != real_size)
        throw std::runtime_error(number + " it's not a number!");

    if(real_size == std::string::npos) real_size = number.length();
}
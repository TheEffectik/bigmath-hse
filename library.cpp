#include<iostream>
#include<string>
#include "library.h"

bignum::bignum()
{
    number = "0";
    sign = false;
    size = 0;
    real_size = 0;
}

bignum::bignum(int x) {
    if(x < 0) {
        sign = false;
        x *= -1;
    }
    (*this).number = std::to_string(x);
    size = number.length();
    real_size = size;
}

bignum::bignum(float x) {
    if(x < 0) {
        (*this).sign = false;
        x *= -1;
    }
    (*this).number = std::to_string(x);
}

int main(){
    float x = 1.2;
    const bignum res(x);
    std::cout << res.number;
}

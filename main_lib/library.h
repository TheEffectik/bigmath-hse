#ifndef MATH_LIBRARY_H
#define MATH_LIBRARY_H

#include<iostream>
#include<string>

namespace bigNum{
    class bignum {

    public:
        bignum();
        bignum(int x);
        bignum(long long x);
        bignum(float x);
        bignum(double x);
        bignum(std::string x);
        static bignum uadd(const bignum& a, const bignum& b); // add to private
        static bignum udiv(const bignum& a, const bignum& b); // add to private

        std::string number;
        int real_size;
        bool sign;
    };
}
bigNum::bignum operator""_bn(const char* str);
bigNum::bignum operator-(const bigNum::bignum &a);


#endif //MATH_LIBRARY_H

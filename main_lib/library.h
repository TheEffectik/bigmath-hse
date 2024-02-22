#ifndef MATH_LIBRARY_H
#define MATH_LIBRARY_H

#include<iostream>
#include<string>
#include<vector>

namespace bigNum {
    class bignum {

    public:
        bignum();

        bignum(int x);

        bignum(long long x);

        bignum(float x);

        bignum(double x);

        bignum(std::string x);

        static bignum uadd(const bignum &a, const bignum &b); // add to private
        static bignum add(const bignum &a, const bignum &b); // add to private
        static bignum usub(const bignum &a, const bignum &b); // add to private
        static bignum sub(const bignum &a, const bignum &b); // add to private

        static bignum mul(const bignum &a, const bignum &b); // add to private
        static bignum div(const bignum &a, const bignum &b, int precision); //  add to private

        friend bool operator>(const bignum &a, const bignum &b);

        friend bool operator<(const bignum &a, const bignum &b);

        friend bool operator>=(const bignum &a, const bignum &b);

        friend bool operator<=(const bignum &a, const bignum &b);

        friend bool operator==(const bignum &a, const bignum &b);

        friend bignum operator+(const bignum &a, const bignum &b);
        friend bignum operator-(const bignum &a, const bignum &b);
        friend bignum operator*(const bignum &a, const bignum &b);
        friend bignum operator/(const bignum &a, const bignum &b);

        static bignum pi(int precision);

        std::string number;
        int real_size;
        bool sign;
    };
}


bigNum::bignum operator ""_bn(const char *str);

bigNum::bignum operator-(const bigNum::bignum &a);


#endif //MATH_LIBRARY_H

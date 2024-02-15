#ifndef MATH_LIBRARY_H
#define MATH_LIBRARY_H

#include<iostream>
#include<string>

class bignum {

    public:
        bignum();
        bignum(int x);
        bignum(float x);
        bignum(double x);

    std::string number;
    size_t real_size;
    bool sign;
};

#endif //MATH_LIBRARY_H

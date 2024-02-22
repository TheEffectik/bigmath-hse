#include <iostream>
#include "gtest/gtest.h"
#include "library.h"

using namespace bigNum;

TEST(div, uint){
    bignum a = 123_bn;
    bignum b = 23_bn;

    bignum c = bignum::udiv(a, b);
    ASSERT_EQ(c.real_size, 3);
    ASSERT_EQ(c.number, "100");

    b = 123_bn;
    c = bignum::udiv(a, b);
    ASSERT_EQ(c.real_size, 1);
    ASSERT_EQ(c.number, "0");

    b = 0.1_bn;
    c = bignum::udiv(a, b);
    ASSERT_EQ(c.real_size, 3);
    ASSERT_EQ(c.number, "1229");

    b = 0.01_bn;
    c = bignum::udiv(a, b);
    ASSERT_EQ(c.real_size, 3);
    ASSERT_EQ(c.number, "12299");

    a = 1000000_bn;
    b = 1;
    c = bignum::udiv(a, b);
    ASSERT_EQ(c.number, "999999");

    a = 2010_bn;
    b = 2009_bn;
    c = bignum::udiv(a, b);
    ASSERT_EQ(c.number, "1");
}
#include <iostream>
#include "gtest/gtest.h"
#include "library.h"

TEST(TestOfcasts, RealSizeInNUmbers) {
    bignum x = bignum(100.23);

    ASSERT_EQ(x.real_size, 3);

    x = bignum(123);

    ASSERT_EQ(x.real_size, 3);

    x = 132;

    ASSERT_EQ(x.real_size, 3);

    float a = 100.23;

    ASSERT_EQ(bignum(a).real_size, 3);

    a = 100;

    ASSERT_EQ(bignum(a).real_size, 3);

    double b = 100.23;

    ASSERT_EQ(bignum(a).real_size, 3);

    b = 100;

    ASSERT_EQ(bignum(a).real_size, 3);
}


TEST(TestOfCasts, SignInNumbers) {
    bignum x = bignum(-1);

    ASSERT_EQ(x.sign, true);

    x = bignum(-1.123);

    ASSERT_EQ(x.sign, true);

    x = bignum(123.123);

    ASSERT_EQ(x.sign, false);

    x = bignum(1);

    ASSERT_EQ(x.sign, false);
}

TEST(TestOfCast, String) {
    bignum x("123");


    ASSERT_EQ(x.sign, false);

    ASSERT_EQ(x.real_size, 3);

    ASSERT_EQ(x.number, "123");
}

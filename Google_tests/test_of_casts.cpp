#include <iostream>
#include "gtest/gtest.h"
#include "library.h"

TEST(TestOfcasts, RealSize) {
    bignum x = bignum(100.23);

    ASSERT_EQ(x.real_size, 3);
}


TEST(TestOfCasts, Sign) {
    bignum x = bignum(-1);

    ASSERT_EQ(x.sign, true);

    x = bignum(-1.123);

    ASSERT_EQ(x.sign, true);

    x = bignum(123.123);

    ASSERT_EQ(x.sign, false);

    x = bignum(1);

    ASSERT_EQ(x.sign, false);
}

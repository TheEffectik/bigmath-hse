#include "gtest/gtest.h"
#include "library.h"

using namespace bigNum;

TEST(compare, more) {
    bignum a, b;
    a = 123_bn;
    b = 23_bn;

    ASSERT_EQ(a > b, true);
    ASSERT_EQ(b > a, false);

    a = 123_bn;
    b = 123_bn;
    ASSERT_EQ(a > b, false);
    ASSERT_EQ(b > a, false);

    a = 123_bn;
    b = 122_bn;
    ASSERT_EQ(a > b, true);
    ASSERT_EQ(b > a, false);

    a = 123_bn;
    b = 124_bn;
    ASSERT_EQ(a > b, false);
    ASSERT_EQ(b > a, true);

    a = 123_bn;
    b = 123.23_bn;
    ASSERT_EQ(a > b, false);
    ASSERT_EQ(b > a, true);

    a = 123_bn;
    b = 123.23_bn;
    ASSERT_EQ(a > b, false);
    ASSERT_EQ(b > a, true);

    a = 123_bn;
    b = 123.23_bn;
    ASSERT_EQ(a > b, false);
    ASSERT_EQ(b > a, true);

    a = 123_bn;
    b = 123.23_bn;
    ASSERT_EQ(a > b, false);
    ASSERT_EQ(b > a, true);

    a = -123_bn;
    b = -123.23_bn;
    ASSERT_EQ(a > b, true);

    a = -123_bn;
    b = -123.00000000000000000000_bn;
    ASSERT_EQ(a > b, false);
    ASSERT_EQ(b > a, false);
    ASSERT_EQ(a == b, true);
    ASSERT_EQ(a >= b, true);
    ASSERT_EQ(b >= a, true);
}
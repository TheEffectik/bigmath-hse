#include "gtest/gtest.h"
#include "library.h"

using namespace bigNum;

TEST(division, uint) {
    bignum a, b, c;
    b = 123_bn;
    a = 123_bn;
    c = bignum::div(a, b, 0);
    ASSERT_EQ(c.number, "1");
    ASSERT_EQ(c.real_size, 1);
    ASSERT_EQ(c.sign, false);

    a = 123_bn;
    b = 22_bn;
    c = bignum::div(a, b, 0);
    ASSERT_EQ(c.number, "5");
    ASSERT_EQ(c.real_size, 1);

    a = 22_bn;
    b = 34_bn;
    c = bignum::div(a, b, 0);
    ASSERT_EQ(c.number, "0");
    ASSERT_EQ(c.real_size, 1);

    a = 123_bn;
    b = 22_bn;
    c = bignum::div(a, b, 1);
    ASSERT_EQ(c.number, "55");
    ASSERT_EQ(c.real_size, 1);
}

TEST(division, floats){
    bignum a, b, c;
    a = 123.23_bn;
    b = 123.23_bn;
    c = bignum::div(a, b, 0);
    ASSERT_EQ(c.number, "1");
    ASSERT_EQ(c.real_size, 1);
    ASSERT_EQ(c.sign, false);
}

TEST(division, negative) {
    bignum a, b, c;
    a = -123_bn;
    b = 123_bn;
    c = bignum::div(a, b, 0);
    ASSERT_EQ(c.number, "1");
    ASSERT_EQ(c.real_size, 1);
    ASSERT_EQ(c.sign, true);

    a = 123_bn;
    b = -123_bn;
    c = bignum::div(a, b, 0);
    ASSERT_EQ(c.number, "1");
    ASSERT_EQ(c.real_size, 1);
    ASSERT_EQ(c.sign, true);
}

TEST(division, hardtests){
    bignum a, b, c;
    a = 123123.22_bn;
    b = 0.22_bn;
    c = bignum::div(a, b, 0);
    ASSERT_EQ(c.number, "559651");

    a = 175_bn;
    b = 17_bn;
    c = bignum::div(a, b, 0);
    ASSERT_EQ(c.number, "10");

    a = 175_bn;
    b = 17_bn;
    c = bignum::div(a, b, 1);
    ASSERT_EQ(c.number, "102");

    a = 175_bn;
    b = 18_bn;
    c = bignum::div(a, b, 0);
    ASSERT_EQ(c.number, "9");

    a = 175_bn;
    b = 18_bn;
    c = bignum::div(a, b, 1);
    ASSERT_EQ(c.number, "97");

    a = 175_bn;
    b = 18_bn;
    c = bignum::div(a, b, 2);
    ASSERT_EQ(c.number, "972");

    a = 1_bn;
    b = 100_bn;
    c = bignum::div(a, b, 2);
    ASSERT_EQ(c.number, "001");

    a = 2183.2387_bn;
    b = 123.23_bn;
    c = bignum::div(a, b, 63);
    ASSERT_EQ(c.number, "17716779193378235819199870161486650977846303659823095025561957315");
    ASSERT_EQ(c.real_size, 2);

    b = 123.2311_bn;
    c = bignum::div(a, b, 63);
    ASSERT_EQ(c.number, "17716621047771220089733841538377893242858336897098216278196007339");
    ASSERT_EQ(c.real_size, 2);

    a = 1;
    b = 4096;
    c = bignum::div(a, b, 100);
}


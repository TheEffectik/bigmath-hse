#include "gtest/gtest.h"
#include "library.h"

using namespace bigNum;

//TEST(sub, usub) {
//    bignum a = 123_bn;
//    bignum b = 23_bn;
//
//    bignum c = bignum::usub(a, b);
//    ASSERT_EQ(c.real_size, 3);
//    ASSERT_EQ(c.number, "100");
//
//    b = 123_bn;
//    c = bignum::usub(a, b);
//    ASSERT_EQ(c.real_size, 1);
//    ASSERT_EQ(c.number, "0");
//
//    b = 0.1_bn;
//    c = bignum::usub(a, b);
//    ASSERT_EQ(c.real_size, 3);
//    ASSERT_EQ(c.number, "1229");
//
//    b = 0.01_bn;
//    c = bignum::usub(a, b);
//    ASSERT_EQ(c.real_size, 3);
//    ASSERT_EQ(c.number, "12299");
//
//    a = 1000000_bn;
//    b = 1;
//    c = bignum::usub(a, b);
//    ASSERT_EQ(c.number, "999999");
//
//    a = 2010_bn;
//    b = 2009_bn;
//    c = bignum::usub(a, b);
//    ASSERT_EQ(c.number, "1");
//}

TEST(sub, negative) {
    bignum a = -123_bn;
    bignum b = 123_bn;
    bignum c = bignum::sub(a, b);
    ASSERT_EQ(c.number, "246");
    ASSERT_EQ(c.real_size, 3);
    ASSERT_EQ(c.sign, true);

    a = 123_bn;
    b = -123_bn;
    c = bignum::sub(a, b);
    ASSERT_EQ(c.number, "246");
    ASSERT_EQ(c.real_size, 3);
    ASSERT_EQ(c.sign, false);
}

TEST(sub, subdouble) {
    bignum a = 123.23_bn;
    bignum b = 123.23_bn;
    bignum c = bignum::sub(a, b);
    ASSERT_EQ(c.number, "0");
    ASSERT_EQ(c.real_size, 1);

    b = 22.2223_bn;
    c = bignum::sub(a, b);
    ASSERT_EQ(c.number, "1010077");
    ASSERT_EQ(c.real_size, 3);
}

TEST(sub, doble_uint) {
    bignum a = 123.23_bn;
    bignum b = 123_bn;
    bignum c = bignum::sub(a, b);
    ASSERT_EQ(c.number, "023");
    ASSERT_EQ(c.real_size, 1);

    b = 22_bn;
    c = bignum::sub(a, b);
    ASSERT_EQ(c.number, "10123");
    ASSERT_EQ(c.real_size, 3);
}

TEST(sub, negative_double) {
    bignum a = -123.23_bn;
    bignum b = 123_bn;
    bignum c = bignum::sub(a, b);
    ASSERT_EQ(c.number, "24623");
    ASSERT_EQ(c.real_size, 3);
    ASSERT_EQ(c.sign, true);

    a = 123_bn;
    b = -123.23_bn;
    c = bignum::sub(a, b);
    ASSERT_EQ(c.number, "24623");
    ASSERT_EQ(c.real_size, 3);
    ASSERT_EQ(c.sign, false);
}

TEST(sub, negative_double2) {
    bignum a = -123.23_bn;
    bignum b = 123.23_bn;
    bignum c = bignum::sub(a, b);
    ASSERT_EQ(c.number, "24646");
    ASSERT_EQ(c.real_size, 3);
    ASSERT_EQ(c.sign, true);

    a = 123.23_bn;
    b = -123.23_bn;
    c = bignum::sub(a, b);
    ASSERT_EQ(c.number, "24646");
    ASSERT_EQ(c.real_size, 3);
    ASSERT_EQ(c.sign, false);
}

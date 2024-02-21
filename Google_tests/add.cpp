#include <iostream>
#include "gtest/gtest.h"
#include "library.h"

using namespace bigNum;

 TEST(adding, uint){
    bignum a = 123_bn;
    ASSERT_EQ(a.number, "123");
    ASSERT_EQ(a.real_size, a.number.length());
    bignum b = 123_bn;
    bignum c = bignum::uadd(a, b);
    ASSERT_EQ(c.number, "246");
    ASSERT_EQ(c.real_size, 3);
    ASSERT_EQ(c.sign, false);

    b = 22_bn;
    c = bignum::uadd(a, b);
    ASSERT_EQ(c.number, "145");
    ASSERT_EQ(c.real_size, 3);
}

TEST(adding, udouble) {
    bignum a = 123.23_bn;
    bignum b = 123.23_bn;
    bignum c = bignum::uadd(a, b);
    ASSERT_EQ(c.number, "24646");
    ASSERT_EQ(c.real_size, 3);

    b = 22.2223_bn;
    c = bignum::uadd(a, b);

    ASSERT_EQ(c.number, "1454523");
    ASSERT_EQ(c.real_size, 3);
}

TEST(adding, udoble_uint){
    bignum a = 123.23_bn;
    bignum b = 123_bn;
    bignum c = bignum::uadd(a, b);
    ASSERT_EQ(c.number, "24623");
    ASSERT_EQ(c.real_size, 3);

    b = 22_bn;
    c = bignum::uadd(a, b);
    ASSERT_EQ(c.number, "14523");
    ASSERT_EQ(c.real_size, 3);
}
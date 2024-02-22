#include "gtest/gtest.h"
#include "library.h"

using namespace bigNum;

TEST(multiplication, uint){
    bignum a = 123_bn;
    bignum b = 123_bn;
    bignum c = bignum::mul(a, b);
    ASSERT_EQ(c.number, "15129");
    ASSERT_EQ(c.real_size, 5);
    ASSERT_EQ(c.sign, false);

    b = 22_bn;
    c = bignum::mul(a, b);
    ASSERT_EQ(c.number, "2706");
    ASSERT_EQ(c.real_size, 4);
}

TEST(multiplication, udouble) {
    bignum a = 123.23_bn;
    bignum b = 123.23_bn;
    bignum c = bignum::mul(a, b);
    ASSERT_EQ(c.number, "151856329");
    ASSERT_EQ(c.real_size, 5);

    b = 22.2223_bn;
    c = bignum::mul(a, b);

    ASSERT_EQ(c.number, "2738454029");
    ASSERT_EQ(c.real_size, 4);
}

TEST(multiplication, udoble_uint){
    bignum a = 123.23_bn;
    bignum b = 123_bn;
    bignum c = bignum::mul(a, b);
    ASSERT_EQ(c.number, "1515729");
    ASSERT_EQ(c.real_size, 5);

    b = 22_bn;
    c = bignum::mul(a, b);
    ASSERT_EQ(c.number, "271106");
    ASSERT_EQ(c.real_size, 4);
}


TEST(multiplication, negative){
    bignum a = -123_bn;
    bignum b = 123_bn;
    bignum c = bignum::mul(a, b);
    ASSERT_EQ(c.number, "15129");
    ASSERT_EQ(c.real_size, 5);
    ASSERT_EQ(c.sign, true);

    a = 123_bn;
    b = -123_bn;
    c = bignum::mul(a, b);
    ASSERT_EQ(c.number, "15129");
    ASSERT_EQ(c.real_size, 5);
    ASSERT_EQ(c.sign, true);

    a = -123_bn;
    b = -123_bn;
    c = bignum::mul(a, b);
    ASSERT_EQ(c.number, "15129");
    ASSERT_EQ(c.real_size, 5);
    ASSERT_EQ(c.sign, false);
}
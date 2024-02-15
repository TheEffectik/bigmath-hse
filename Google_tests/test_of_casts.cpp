#include <iostream>
#include "gtest/gtest.h"
#include "library.h"

TEST(AbsoluteDateTestSuite, ExampleNumber) {
    bignum bigNumber = bignum(100);

    ASSERT_EQ(bigNumber.number, "100");
}

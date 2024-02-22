#include "gtest/gtest.h"
#include "library.h"

using namespace bigNum;

TEST(pi, chekc){
    bignum a = bignum::pi(100);
    std::cout << a.number;
}
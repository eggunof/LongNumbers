
#include <gtest/gtest.h>

#include "rational.h"

TEST(RationalTest, Dummy) { EXPECT_TRUE(true); }

TEST(RationalTest, IsIntTest){
    Rational rational1("1/3");
    EXPECT_FALSE(rational1.IsInteger());
    Rational rational2("-5322/1");
    EXPECT_TRUE(rational2.IsInteger());
    Rational rational3("10/2");
    EXPECT_TRUE(rational3.IsInteger());
    Rational rational4("17/34");
    EXPECT_FALSE(rational4.IsInteger());
    Rational rational5("0");
    EXPECT_TRUE(rational5.IsInteger());
}

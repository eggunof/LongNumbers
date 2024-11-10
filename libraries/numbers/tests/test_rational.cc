
#include <gtest/gtest.h>

#include "rational.h"

TEST(RationalTest, Dummy) { EXPECT_TRUE(true); }

TEST(RationalTest, AddDenominators) {
  Rational r1(Integer(1), Natural(3));
  Rational r2(Integer(1), Natural(6));
  r1-=r2;
  Rational expected_r1_r2(Integer(1), Natural(6));
  EXPECT_EQ(r1, expected_r1_r2);

  Rational r3(Integer(1), Natural(4));
  Rational r4(Integer(1), Natural(4));
  r3-=r4;
  Rational expected_r3_r4(Integer(0), Natural(1));
  EXPECT_EQ(r3, expected_r3_r4);

}
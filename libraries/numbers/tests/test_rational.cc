
#include <gtest/gtest.h>

#include "rational.h"

TEST(RationalTest, Dummy) { EXPECT_TRUE(true); }

TEST(RationalTest, AddDenominators) {
  Rational r1(Integer(1), Natural(3));
  Rational r2(Integer(1), Natural(6));
  Rational expected_r1_r2(Integer(1), Natural(2));
  EXPECT_EQ(r1 + r2, expected_r1_r2);
  
  Rational r3(Integer(1), Natural(4));
  Rational r4(Integer(1), Natural(4));
  Rational expected_r3_r4(Integer(1), Natural(2));
  EXPECT_EQ(r3 + r4, expected_r3_r4);

  Rational r5(Integer(0), Natural(1));
  Rational r6(Integer(3), Natural(5));
  Rational expected_r5_r6(Integer(3), Natural(5));
  EXPECT_EQ(r5 + r6, expected_r5_r6);
}

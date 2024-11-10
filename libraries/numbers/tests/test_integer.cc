
#include <gtest/gtest.h>

#include "integer.h"

TEST(IntegerTest, Sign) {
  Integer integer({1, 2, 3}, Sign::POSITIVE);
  EXPECT_EQ(integer.GetSign(), Sign::POSITIVE);

  Integer negative_integer({1, 2, 3}, Sign::NEGATIVE);
  EXPECT_EQ(negative_integer.GetSign(), Sign::NEGATIVE);

  Integer zero_integer({0}, Sign::ZERO);
  EXPECT_EQ(zero_integer.GetSign(), Sign::ZERO);

  Integer negative_zero_integer({0}, Sign::NEGATIVE);
  EXPECT_EQ(negative_zero_integer.GetSign(), Sign::ZERO);
}

TEST(IntegerTest, Multiplication) {
  Integer a({1, 2, 3}, Sign::POSITIVE);
  Integer b({4, 5, 6}, Sign::POSITIVE);
  Integer expected_positive({5, 6, 0, 8, 8}, Sign::POSITIVE);
  EXPECT_EQ(a * b, expected_positive);

  Integer expected_negative({5, 6, 0, 8, 8}, Sign::NEGATIVE);
  EXPECT_EQ(a * Integer({4, 5, 6}, Sign::NEGATIVE), expected_negative);

  EXPECT_EQ(Integer({1, 2, 3}, Sign::NEGATIVE) * Integer({4, 5, 6}, Sign::NEGATIVE), expected_positive);

  Integer zero({0}, Sign::ZERO);
  Integer expected_zero({0}, Sign::ZERO);
  EXPECT_EQ(a * zero, expected_zero);
  EXPECT_EQ(zero * a, expected_zero);

  EXPECT_EQ(zero * zero, expected_zero);
}

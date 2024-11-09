
#include <gtest/gtest.h>

#include "../include/integer.h"

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
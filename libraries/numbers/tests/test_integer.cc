
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

TEST(IntegerTest, sub){
  Integer a1({1, 2, 3}, Sign::POSITIVE);
  Integer b1({1, 2, 3}, Sign::NEGATIVE);
  Integer c1({2,4,6}, Sign::POSITIVE);
  EXPECT_EQ(a1 - b1, c1);

  Integer a2({1, 2, 3}, Sign::POSITIVE);
  Integer b2({1, 2, 3}, Sign::POSITIVE);
  Integer c2({0}, Sign::ZERO);
  EXPECT_EQ(a2 - b2, c2);

  Integer a3({1, 2, 3}, Sign::POSITIVE);
  Integer b3({2, 4, 6}, Sign::POSITIVE);
  Integer c3({1,2,3}, Sign::NEGATIVE);
  EXPECT_EQ(a3 - b3, c3);
}

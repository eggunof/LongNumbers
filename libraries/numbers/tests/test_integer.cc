
#include <gtest/gtest.h>

#include "integer.h"

TEST(IntegerTest, Sign) {
  Integer integer({1, 2, 3}, Sign::POSITIVE);
  EXPECT_EQ(integer.GetSign(), Sign::POSITIVE);

  Integer negative_integer({1, 2, 3}, Sign::NEGATIVE);
  EXPECT_EQ(negative_integer.GetSign(), Sign::NEGATIVE);

  Integer zero_integer({0, 0, 0}, Sign::ZERO);
  EXPECT_EQ(zero_integer.GetSign(), Sign::ZERO);

  Integer negative_zero_integer({0, 0}, Sign::NEGATIVE);
  EXPECT_EQ(negative_zero_integer.GetSign(), Sign::ZERO);
}

TEST(IntegerTest, Multiplication) {
  Integer a("123");
  Integer b("456");
  EXPECT_EQ(a * b, Integer("56088"));
  Integer c("-123");
  Integer d("456");
  EXPECT_EQ(c * d, Integer("-56088"));
  Integer e("-123");
  Integer f("-456");
  EXPECT_EQ(e * f, Integer("56088"));
  Integer g("0");
  Integer h("456");
  EXPECT_EQ(g * h, Integer("0"));
}

TEST(IntegerTest, IntegerToNatural) {
  Integer a("0");
  EXPECT_EQ(Natural(a), Natural("1"));

  Integer b("50000000099999999");
  EXPECT_EQ(Natural(b), Natural("50000000099999999"));
}

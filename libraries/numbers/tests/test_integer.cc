
#include <gtest/gtest.h>

#include "integer.h"

TEST(IntegerTest, IntegerToNatural) {
  Integer a("8641561246");
  EXPECT_EQ(Natural(a), Natural("8641561246"));

  Integer b("0");
  EXPECT_EQ(Natural(b), Natural("0"));

  Integer c("-8641561246");
  EXPECT_THROW(static_cast<Natural>(c), std::invalid_argument);
}

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

TEST(IntegerTest, Addition){
  Integer a1({1, 2, 3}, Sign::POSITIVE);
  Integer b1({1, 2, 3}, Sign::POSITIVE);
  Integer c1({2,4,6}, Sign::POSITIVE);
  EXPECT_EQ(a1 + b1, c1);

  Integer a2({1, 2, 3}, Sign::POSITIVE);
  Integer b2({1, 2, 3}, Sign::NEGATIVE);
  Integer c2({0}, Sign::ZERO);
  EXPECT_EQ(a2 + b2, c2);

  Integer a3({1, 2, 3}, Sign::POSITIVE);
  Integer b3({2, 4, 6}, Sign::NEGATIVE);
  Integer c3({1,2,3}, Sign::NEGATIVE);
  EXPECT_EQ(a3 + b3, c3);
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

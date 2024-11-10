
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

TEST(IntegerTest, Addition) {
  Integer a("4846512846");
  Integer b("98456198645");
  a += b;
  EXPECT_EQ(a, Integer("103302711491"));

  Integer c("4846512846");
  Integer d("-98456198645");
  c += d;
  EXPECT_EQ(c, Integer("-93609685799"));

  Integer e("-4846512846");
  Integer f("-98456198645");
  e += f;
  EXPECT_EQ(e, Integer("-103302711491"));

  Integer g("1234567890");
  Integer h("-1234567890");
  EXPECT_EQ(g + h, Integer("0"));
}

TEST(IntegerTest, Subtraction) {
  Integer a("1234567890");
  Integer b("98456198645");
  a -= b;
  EXPECT_EQ(a, Integer("-86110520745"));

  Integer c("1234567890");
  Integer d("-98456198645");
  c -= d;
  EXPECT_EQ(c, Integer("100010916895"));

  Integer e("1234567890");
  Integer f("1234567890");
  e -= f;
  EXPECT_EQ(e, Integer("0"));

  Integer g("0");
  Integer h("456");
  EXPECT_EQ(g - h, Integer("-456"));
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

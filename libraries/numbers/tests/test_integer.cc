
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

TEST(IntegerTest, AbsoluteValue) {
  Integer a("8641561246");
  EXPECT_EQ(Integer::AbsoluteValue(a), Integer("8641561246"));

  Integer b("0");
  EXPECT_EQ(Integer::AbsoluteValue(b), Integer("0"));

  Integer c("-8641561246");
  EXPECT_EQ(Integer::AbsoluteValue(c), Integer("8641561246"));
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

TEST(IntegerTest, Negation) {
  Integer a("4846512846");
  -a;
  EXPECT_EQ(a, Integer("-4846512846"));

  Integer b("-4846512846");
  -b;
  EXPECT_EQ(b, Integer("4846512846"));

  Integer c("0");
  -c;
  EXPECT_EQ(c, Integer("0"));
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
  EXPECT_EQ(a, Integer("-97221630755"));

  Integer c("1234567890");
  Integer d("-98456198645");
  c -= d;
  EXPECT_EQ(c, Integer("99690766535"));

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

TEST(IntegerTest, ModTests){
    Integer integer1("25");
    Integer rhs1("7");
    Integer res1("4");
    EXPECT_EQ(integer1 % rhs1, res1);
    Integer integer2("-25");
    Integer rhs2("7");
    Integer res2("3");
    EXPECT_EQ(integer2 %rhs2, res2);
    Integer integer3("45");
    Integer rhs3("-9");
    Integer res3("0");
    EXPECT_EQ(integer3 %= rhs3, res3);
    Integer integer4("17");
    Integer rhs4("34");
    Integer res4("17");
    EXPECT_EQ(integer4 % rhs4, res4);
    Integer integer5("-17");
    Integer rhs5("7");
    Integer res5("4");
    EXPECT_EQ(integer5 % rhs5, res5);
    Integer integer6("123456789");
    Integer rhs6("234");
    Integer res6("27");
    EXPECT_EQ(integer6 % rhs6, res6);
}

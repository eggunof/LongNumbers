
#include <gtest/gtest.h>

#include "integer.h"

TEST(IntegerTest, NaturalToInteger) {
  Natural a("12345678901234567890");
  EXPECT_EQ(Integer(a), Integer("12345678901234567890"));

  Natural b("98877665255252626266266262525");
  EXPECT_EQ(Integer(b), Integer("98877665255252626266266262525"));

  Natural c("0");
  EXPECT_EQ(Integer(c), Integer("0"));
}

TEST(IntegerTest, IntegerToNatural) {
  Integer a("8641561246");
  EXPECT_EQ(Natural(a), Natural("8641561246"));

  Integer b("0");
  EXPECT_EQ(Natural(b), Natural("0"));

  Integer c("-8641561246");
  EXPECT_THROW(auto d = Natural(c), std::invalid_argument);
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
  Integer a("123");
  EXPECT_EQ(a.GetSign(), Sign::POSITIVE);

  Integer b("0");
  EXPECT_EQ(b.GetSign(), Sign::ZERO);

  Integer c("-4846512846");
  EXPECT_EQ(c.GetSign(), Sign::NEGATIVE);
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

TEST(IntegerTest, DivisionQuotient) {
  Integer a("78");
  Integer b("33");
  a /= b;
  EXPECT_EQ(a, Integer("2"));

  Integer c("-78");
  Integer d("33");
  c /= d;
  EXPECT_EQ(c, Integer("-3"));

  Integer e("-78");
  Integer f("-33");
  e /= f;
  EXPECT_EQ(e, Integer("3"));

  Integer g("10");
  Integer h("33");
  g /= h;
  EXPECT_EQ(g, Integer("0"));

  Integer i("-10");
  Integer j("33");
  i /= j;
  EXPECT_EQ(i, Integer("-1"));

  Integer k("-10");
  Integer l("-33");
  k /= l;
  EXPECT_EQ(k, Integer("1"));

  Integer m("123");
  Integer n("0");
  EXPECT_THROW(m / n, std::invalid_argument);
}

TEST(IntegerTest, DivisionRemainder) {
  Integer a("78");
  Integer b("33");
  a %= b;
  EXPECT_EQ(a, Integer("12"));

  Integer c("-78");
  Integer d("33");
  c %= d;
  EXPECT_EQ(c, Integer("21"));

  Integer e("10");
  Integer f("33");
  e %= f;
  EXPECT_EQ(e, Integer("10"));

  Integer g("-10");
  Integer h("33");
  g %= h;
  EXPECT_EQ(g, Integer("23"));

  Integer i("123");
  Integer j("0");
  EXPECT_THROW(i % j, std::invalid_argument);
}

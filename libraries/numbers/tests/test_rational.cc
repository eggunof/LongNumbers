
#include <gtest/gtest.h>

#include "rational.h"

TEST(RationalTest, IntegerToRational) {
  Integer a("46532186");
  EXPECT_EQ(static_cast<Rational>(a), Rational("46532186"));

  Integer b("0");
  EXPECT_EQ(static_cast<Rational>(b), Rational("0"));

  Integer c("-65431864");
  EXPECT_EQ(static_cast<Rational>(c), Rational("-65431864"));
}

TEST(RationalTest, RationalToInteger) {
  Rational a("1564/4");
  EXPECT_EQ(static_cast<Integer>(a), Integer("391"));

  Rational b("-7087572768/453");
  EXPECT_EQ(static_cast<Integer>(b), Integer("-15645856"));

  Rational c("1/2");
  EXPECT_THROW(auto d = static_cast<Integer>(c), std::invalid_argument);
}

TEST(RationalTest, Reduce) {
  Rational a("25/5");
  a.Reduce();
  EXPECT_EQ(a, Rational("5/1"));

  Rational b("123456789999333/9876543211234");
  b.Reduce();
  EXPECT_EQ(b, Rational("17636684285619/1410934744462"));

  Rational c("1234567891234567/123");
  c.Reduce();
  EXPECT_EQ(c, Rational("1234567891234567/123"));

  Rational d("-674748493870000/477484848784");
  d.Reduce();
  EXPECT_EQ(d, Rational("-42171780866875/29842803049"));
}

TEST(RationalTest, IsInteger) {
  Rational a("1/3");
  EXPECT_FALSE(a.IsInteger());

  Rational b("-5322/1");
  EXPECT_TRUE(b.IsInteger());

  Rational c("10/2");
  EXPECT_TRUE(c.IsInteger());

  Rational d("17/34");
  EXPECT_FALSE(d.IsInteger());

  Rational e("0");
  EXPECT_TRUE(e.IsInteger());
}

TEST(RationalTest, AddDenominators) {
  Rational a("1/3");
  Rational b("1/6");
  a += b;
  EXPECT_EQ(a, Rational("1/2"));

  Rational c("-3/4");
  Rational d("1/10");
  c += d;
  EXPECT_EQ(c, Rational("-13/20"));

  Rational e("-4563486/64231864");
  Rational f("15646431/16542313");
  EXPECT_EQ(e + f, Rational("464754407147133/531271799430716"));
}

TEST(RationalTest, Division) {
  Rational a("-9/2");
  Rational b("7/4");
  EXPECT_EQ(a /= b, Rational("-18/7"));

  Rational c("1500000000000000/120000000000001");
  Rational d("50000000000000/24400000000000000");
  EXPECT_EQ(c /= d, Rational("732000000000000000/120000000000001"));

  Rational e("-18000000000000000/9000000000000000");
  Rational f("-3000000000000000/200000000000");
  EXPECT_EQ(e /= f, Rational("1/7500"));
}

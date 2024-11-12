
#include <gtest/gtest.h>

#include "rational.h"

TEST(RationalTest, Compare) {
  Rational a("123456789/987654321");
  Rational b("1/8");
  Rational g("111111111/222222222");
  Rational d("1/2");

  EXPECT_TRUE(a < b);
  EXPECT_TRUE(a <= d);
  EXPECT_TRUE(g == d);
  EXPECT_TRUE(b != d);
  EXPECT_FALSE(b > d);
  EXPECT_TRUE(d >= b);
}

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

TEST(RationalTest, Addition) {
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

TEST(RationalTest, Subtraction) {
  Rational a("1/3");
  Rational b("1/6");
  a -= b;
  EXPECT_EQ(a, Rational("1/6"));

  Rational c("-3/4");
  Rational d("1/10");
  c -= d;
  EXPECT_EQ(c, Rational("-17/20"));

  Rational e("-4563486/64231864");
  Rational f("15646431/16542313");
  EXPECT_EQ(e - f, Rational("-540245020930251/531271799430716"));
}

TEST(RationalTest, Multiplication) {
  Rational a("1/3");
  Rational b("1/6");
  a *= b;
  EXPECT_EQ(a, Rational("1/18"));

  Rational c("-3/4");
  Rational d("1/10");
  c *= d;
  EXPECT_EQ(c, Rational("-3/40"));

  Rational e("-1345/45");
  Rational f("453165/456");
  EXPECT_EQ(e * f, Rational("-40633795/1368"));
}

TEST(RationalTest, Division) {
  Rational a("9/2");
  Rational b("7/4");
  a /= b;
  EXPECT_EQ(a, Rational("18/7"));

  Rational c("-3/4");
  Rational d("1/10");
  c /= d;
  EXPECT_EQ(c, Rational("-30/4"));

  Rational e("145/45");
  Rational f("-165/15");
  e /= f;
  EXPECT_EQ(e, Rational("-29/99"));

  Rational g("-54/32");
  Rational h("-455/25");
  g /= h;
  EXPECT_EQ(g, Rational("135/1456"));

  Rational i("0");
  Rational j("10");
  i /= j;
  EXPECT_EQ(i, Rational("0"));

  Rational k("10/2");
  Rational l("0");
  EXPECT_THROW(k / l, std::invalid_argument);
}

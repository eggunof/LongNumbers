
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
  Rational r1(Integer(1), Natural(3));
  Rational r2(Integer(1), Natural(6));
  Rational expected_r1_r2(Integer(1), Natural(2));
  EXPECT_EQ(r1 + r2, expected_r1_r2);

  Rational r3(Integer(1), Natural(4));
  Rational r4(Integer(1), Natural(4));
  Rational expected_r3_r4(Integer(1), Natural(2));
  EXPECT_EQ(r3 + r4, expected_r3_r4);

  Rational r5(Integer(0), Natural(1));
  Rational r6(Integer(3), Natural(5));
  Rational expected_r5_r6(Integer(3), Natural(5));
  EXPECT_EQ(r5 + r6, expected_r5_r6);
}

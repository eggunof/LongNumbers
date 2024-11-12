
#include <gtest/gtest.h>

#include "rational.h"

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

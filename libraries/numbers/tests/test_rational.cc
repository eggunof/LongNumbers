
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

TEST(RationalTest, IsIntTest){
    Rational rational1("1/3");
    EXPECT_FALSE(rational1.IsInteger());
    Rational rational2("-5322/1");
    EXPECT_TRUE(rational2.IsInteger());
    Rational rational3("10/2");
    EXPECT_TRUE(rational3.IsInteger());
    Rational rational4("17/34");
    EXPECT_FALSE(rational4.IsInteger());
    Rational rational5("0");
    EXPECT_TRUE(rational5.IsInteger());
}


#include <gtest/gtest.h>

#include "rational.h"

TEST(RationalTest, Dummy) { EXPECT_TRUE(true); }

TEST(RationalTest, Reduce) {
  Rational a("25/5");
  a.Reduce();
  EXPECT_TRUE(a, Rational("5/1"));

  Rational b("123456789999333/9876543211234");
  b.Reduce();
  EXPECT_TRUE(a, Rational("17636684285619/1410934744462"));

  Rational c("1234567891234567/123");
  c.Reduce();
  EXPECT_TRUE(a, Rational("1234567891234567/123"));
}

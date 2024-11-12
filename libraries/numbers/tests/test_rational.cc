
#include <gtest/gtest.h>

#include "rational.h"

TEST(RationalTest, Dummy) { EXPECT_TRUE(true); }

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

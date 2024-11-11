
#include <gtest/gtest.h>

#include "rational.h"

TEST(RationalTest, LargeComparisonOperators) {
    Rational e("123456789/987654321");
    Rational f("246913578/1975308642");
    Rational g("111111111/222222222");
    Rational h("567890123/123456789");
    Rational i("1000000000/500000000");

    EXPECT_TRUE(e == f);
    EXPECT_TRUE(g == Rational("1/2"));
    EXPECT_FALSE(e < h);
    EXPECT_TRUE(h > g);
    EXPECT_TRUE(i > Rational("2/1"));

    Rational j("999999999/1000000000");
    Rational k("1000000001/1000000000");
    Rational l("3000000000/1500000000");

    EXPECT_TRUE(j < k);
    EXPECT_TRUE(k > j);
    EXPECT_TRUE(l == Rational("2/1"));
    EXPECT_TRUE(l >= i);

    Rational m("1234567890123456789/9876543210987654321");
    Rational n("246913578024691357876/19753086419753086429");

    EXPECT_TRUE(m == n);
}


#include <gtest/gtest.h>

#include "natural.h"

TEST(NaturalTest, CreateEmpty) {
  Natural natural;
  EXPECT_TRUE(natural.IsZero());
}

TEST(NaturalTest, Compare) {
  Natural first("5246345451");
  Natural second("5263345651");
  EXPECT_EQ(Natural::Compare(first, second), Comparison::LESS);
  EXPECT_FALSE(first == second);
  EXPECT_TRUE(first != second);
  EXPECT_TRUE(first < second);
  EXPECT_FALSE(first > second);
  EXPECT_TRUE(first <= second);
  EXPECT_FALSE(first >= second);
}

TEST(NaturalTest, Addition) {
  Natural a("1046");
  Natural b("599999");
  a += b;
  EXPECT_EQ(a, Natural("601045"));

  Natural c("6541186631");
  Natural d("51866");
  c += d;
  EXPECT_EQ(c, Natural("6541238497"));

  Natural e("123456789");
  Natural f("999999999");
  EXPECT_EQ(e + f, Natural("1123456788"));
}

TEST(NaturalTest, MultiplyByDigit) {
  Natural a("9999999");
  EXPECT_EQ(a *= 9, Natural("89999991"));

  Natural b("5473");
  EXPECT_EQ(b *= 0, Natural("0"));

  Natural c("123456789");
  EXPECT_EQ(c *= 1, Natural("123456789"));

  Natural d("123321");
  EXPECT_EQ(d * 7, Natural("863247"));
}

TEST(NaturalTest, MultiplyBy10Power) {
  Natural a("5000000000");
  a.MultiplyBy10Power(2);
  EXPECT_EQ(a, Natural("500000000000"));

  Natural b("5000000000");
  b.MultiplyBy10Power(0);
  EXPECT_EQ(b, Natural("5000000000"));

  Natural c("0");
  c.MultiplyBy10Power(3);
  EXPECT_EQ(c, Natural("0"));
}

TEST(NaturalTest, LeastCommonMultiple) {
  Natural a("4294967297");
  Natural b("1001021496");
  EXPECT_EQ(Natural::LeastCommonMultiple(a, b), Natural("6707261449163832"));

  Natural c("4294967300");
  Natural d("8589934590");
  EXPECT_EQ(Natural::LeastCommonMultiple(c, d), Natural("3689348817318890500"));

  Natural e("4500000000");
  Natural f("7000000000");
  EXPECT_EQ(Natural::LeastCommonMultiple(e, f), Natural("63000000000"));
}

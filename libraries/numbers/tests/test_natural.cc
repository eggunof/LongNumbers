
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

TEST(NaturalTest, Subtraction) {
  Natural a("23456789");
  Natural b("345678");
  a -= b;
  EXPECT_EQ(a, Natural("23111111"));

  Natural c("9999999999");
  Natural d("1234567890");
  c -= d;
  EXPECT_EQ(c, Natural("8765432109"));

  Natural e("123456789");
  Natural f("0");
  e -= f;
  EXPECT_EQ(e, Natural("123456789"));

  Natural g("0");
  Natural h("1");
  EXPECT_THROW(g - h, std::invalid_argument);

  Natural i("9999999999");
  Natural j("9999999999");
  EXPECT_EQ(i - j, Natural("0"));
}

TEST(NaturalTest, MultiplyByDigit) {
  Natural a("9999999");
  a *= 9;
  EXPECT_EQ(a, Natural("89999991"));

  Natural b("5473");
  b *= 0;
  EXPECT_EQ(b, Natural("0"));

  Natural c("123456789");
  c *= 1;
  EXPECT_EQ(c, Natural("123456789"));

  Natural d("123321");
  EXPECT_EQ(d * 7, Natural("863247"));
}

TEST(NaturalTest, Multiply) {
  Natural a("123456789");
  Natural b("987654321");
  a *= b;
  EXPECT_EQ(a, Natural("121932631112635269"));

  Natural c("1234567890");
  Natural d("0");
  c *= d;
  EXPECT_EQ(c, Natural("0"));

  Natural e("0");
  Natural f("9876543210");
  e *= f;
  EXPECT_EQ(e, Natural("0"));

  Natural g("15468");
  Natural h("98456159884415");
  EXPECT_EQ(g * h, Natural("1522919881092131220"));
}

TEST(NaturalTest, Division) {
  Natural a("30");
  Natural b("3");
  a /= b;
  EXPECT_EQ(a, Natural("10"));

  Natural c("4643121486");
  Natural d("5645631");
  c /= d;
  EXPECT_EQ(c, Natural("822"));

  Natural e("0");
  Natural f("123");
  e /= f;
  EXPECT_EQ(e, Natural("0"));

  Natural g("9999999999999999999999999");
  Natural h("1111111111111111888888");
  g /= h;
  EXPECT_EQ(g, Natural("8999"));

  Natural i("108");
  Natural j("18");
  i /= j;
  EXPECT_EQ(i, Natural("6"));

  Natural k("123");
  Natural l("0");
  EXPECT_THROW(k / l, std::invalid_argument);
}

TEST(NaturalTest, SubtractionMultiplied) {
  Natural a("3896417841");
  Natural b("21564894");
  a.SubtractMultiplied(b, 4);
  EXPECT_EQ(a, Natural("3810158265"));

  Natural c("498616189649");
  Natural d("15689432899");
  c.SubtractMultiplied(d, 3);
  EXPECT_EQ(c, Natural("451547890952"));

  Natural e("1234567890");
  Natural f("1234567890");
  e.SubtractMultiplied(f, 1);
  EXPECT_EQ(e, Natural("0"));

  Natural g("0");
  Natural h("1");
  EXPECT_THROW(g.SubtractMultiplied(h, 1), std::invalid_argument);
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

TEST(NaturalTest, GetLeadingQuotientDigit) {
  Natural a("2");
  Natural b("3");
  auto c = std::make_pair<Digit, uint32_t>(Digit(0), 0);
  EXPECT_EQ(a.GetLeadingQuotientDigit(b), c);

  Natural d("7");
  Natural e("3");
  auto f = std::make_pair<Digit, uint32_t>(Digit(2), 0);
  EXPECT_EQ(d.GetLeadingQuotientDigit(e), f);

  Natural g("23");
  Natural h("3");
  auto i = std::make_pair<Digit, uint32_t>(Digit(7), 0);
  EXPECT_EQ(g.GetLeadingQuotientDigit(h), i);

  Natural j("84");
  Natural k("3");
  auto l = std::make_pair<Digit, uint32_t>(Digit(2), 1);
  EXPECT_EQ(j.GetLeadingQuotientDigit(k), l);

  Natural m("2");
  Natural n("18");
  auto o = std::make_pair<Digit, uint32_t>(Digit(0), 0);
  EXPECT_EQ(m.GetLeadingQuotientDigit(n), o);

  Natural p("1");
  Natural r("0");
  EXPECT_THROW(auto s = p.GetLeadingQuotientDigit(r), std::invalid_argument);
}



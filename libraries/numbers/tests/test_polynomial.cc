
#include <gtest/gtest.h>

#include "polynomial.h"

TEST(PolynomialTest, StringToPolynomial) {
  Polynomial a("3/2*x^5 - 4*x^3 + 1/2*x - 2");
  auto a_map = std::map<Natural, Rational, Comparator>{
      {Natural("5"), Rational("3/2")},
      {Natural("3"), Rational("-4")},
      {Natural("1"), Rational("1/2")},
      {Natural("0"), Rational("-2")},
  };
  EXPECT_EQ(a, Polynomial(a_map));

  Polynomial b("5/3*x^4 + 7*x + 2");
  auto b_map = std::map<Natural, Rational, Comparator>{
      {Natural("4"), Rational("5/3")},
      {Natural("1"), Rational("7")},
      {Natural("0"), Rational("2")},
  };
  EXPECT_EQ(b, Polynomial(b_map));

  Polynomial c(" -3*x^4  + 6/5*x^2 - x +   1/3");
  auto c_map = std::map<Natural, Rational, Comparator>{
      {Natural("4"), Rational("-3")},
      {Natural("2"), Rational("6/5")},
      {Natural("1"), Rational("-1")},
      {Natural("0"), Rational("1/3")},
  };
  EXPECT_EQ(c, Polynomial(c_map));

  Polynomial d("4*x^7 + 5 - x^5 + 1/2*x^2 - 7/8");
  auto d_map = std::map<Natural, Rational, Comparator>{
      {Natural("7"), Rational("4")},
      {Natural("5"), Rational("-1")},
      {Natural("2"), Rational("1/2")},
      {Natural("0"), Rational("33/8")},
  };
  EXPECT_EQ(d, Polynomial(d_map));

  Polynomial e("2*x^3 - 3*x^3 + x + x - 1");
  auto e_map = std::map<Natural, Rational, Comparator>{
      {Natural("3"), Rational("-1")},
      {Natural("1"), Rational("2")},
      {Natural("0"), Rational("-1")},
  };
  EXPECT_EQ(e, Polynomial(e_map));

  Polynomial f("3*x^3 - 3*x^3 + x - x + 2 - 2");
  auto f_map = std::map<Natural, Rational, Comparator>{};
  EXPECT_EQ(f, Polynomial(f_map));

  Polynomial g(" 7 x^3 + 1 / 2 x  - 3 ");
  auto g_map = std::map<Natural, Rational, Comparator>{
      {Natural("3"), Rational("7")},
      {Natural("1"), Rational("1/2")},
      {Natural("0"), Rational("-3")},
  };
  EXPECT_EQ(g, Polynomial(g_map));

  Polynomial h("x^5 - x^2");
  auto h_map = std::map<Natural, Rational, Comparator>{
      {Natural("5"), Rational("1")},
      {Natural("2"), Rational("-1")},
  };
  EXPECT_EQ(h, Polynomial(h_map));
}

TEST(PolynomialTest, Addition) {
  Polynomial pol1({{Natural(0), Rational(Integer(1), Natural(1))},
                   {Natural(1), Rational(Integer(2), Natural(1))},
                   {Natural(2), Rational(Integer(3), Natural(1))},
                   {Natural(3), Rational(Integer(4), Natural(1))}});
  Polynomial pol2({{Natural(0), Rational(Integer(10), Natural(1))},
                   {Natural(2), Rational(Integer(20), Natural(1))},
                   {Natural(3), Rational(Integer(30), Natural(1))},
                   {Natural(10), Rational(Integer(40), Natural(1))}});
  Polynomial pol_expected1({{Natural(0), Rational(Integer(11), Natural(1))},
                            {Natural(1), Rational(Integer(2), Natural(1))},
                            {Natural(2), Rational(Integer(23), Natural(1))},
                            {Natural(3), Rational(Integer(34), Natural(1))},
                            {Natural(10), Rational(Integer(40), Natural(1))}});

  EXPECT_EQ(pol1 += pol2, pol_expected1);

  Polynomial pol3({{Natural(0), Rational(Integer(100), Natural(1))},
                   {Natural(10), Rational(Integer(500), Natural(1))},
                   {Natural(20), Rational(Integer(600), Natural(1))},
                   {Natural(30), Rational(Integer(700), Natural(1))}});
  Polynomial pol4({{Natural(0), Rational(Integer(-100), Natural(1))},
                   {Natural(10), Rational(Integer(-200), Natural(1))},
                   {Natural(20), Rational(Integer(400), Natural(1))},
                   {Natural(30), Rational(Integer(-800), Natural(1))},
                   {Natural(50), Rational(Integer(500), Natural(1))}});
  Polynomial pol_expected2({{Natural(10), Rational(Integer(300), Natural(1))},
                            {Natural(20), Rational(Integer(1000), Natural(1))},
                            {Natural(30), Rational(Integer(-100), Natural(1))},
                            {Natural(50), Rational(Integer(500), Natural(1))}});

  EXPECT_EQ(pol3 += pol4, pol_expected2);
}

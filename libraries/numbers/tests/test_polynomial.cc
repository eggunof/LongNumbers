
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
  Polynomial a("3/2*x^5 - 4*x^3 + 1/2*x - 2");
  Polynomial b("2*x^4 + x^3 - 1/2*x + 3");
  Polynomial c("3/2*x^5 + 2*x^4 - 3*x^3 + 1");
  a += b;
  EXPECT_EQ(a, c);

  Polynomial d("x^3 - 2*x + 5");
  Polynomial e("2*x^3 + 3*x - 1");
  Polynomial f("3*x^3 + x + 4");
  d += e;
  EXPECT_EQ(d, f);

  Polynomial g("3*x^4 + x^2 - x");
  Polynomial h("-3*x^4 - x^2 + 2*x + 5");
  Polynomial i("x + 5");
  g += h;
  EXPECT_EQ(g, i);

  Polynomial j("2*x^3 + 3*x^2 - x + 7");
  Polynomial k("0");
  Polynomial l("2*x^3 + 3*x^2 - x + 7");
  j += k;
  EXPECT_EQ(j, l);

  Polynomial m("x^4 - 3*x^2 + x - 6");
  Polynomial n("-x^4 + 3*x^2 - x + 6");
  Polynomial o("0");
  EXPECT_EQ(m + n, o);

  Polynomial p("1/2*x^2 + 3/4*x - 1/3");
  Polynomial q("2/3*x^2 - 3/4*x + 1/6");
  Polynomial r("7/6*x^2 - 1/6");
  EXPECT_EQ(p + q, r);
}

TEST(PolynomialTest, Subtraction) {
  Polynomial a("3/2*x^5 - 4*x^3 + 1/2*x - 2");
  Polynomial b("2*x^4 + x^3 - 1/2*x + 3");
  Polynomial c("3/2*x^5 - 2*x^4 - 5*x^3 + x - 5");
  a -= b;
  EXPECT_EQ(a, c);

  Polynomial d("x^3 - 2*x + 5");
  Polynomial e("2*x^3 + 3*x - 1");
  Polynomial f("-x^3 - 5*x + 6");
  d -= e;
  EXPECT_EQ(d, f);

  Polynomial g("3*x^4 + x^2 - x");
  Polynomial h("3*x^4 + x^2 - 2*x - 5");
  Polynomial i("x + 5");
  g -= h;
  EXPECT_EQ(g, i);

  Polynomial j("2*x^3 + 3*x^2 - x + 7");
  Polynomial k("0");
  Polynomial l("2*x^3 + 3*x^2 - x + 7");
  j -= k;
  EXPECT_EQ(j, l);

  Polynomial m("x^4 - 3*x^2 + x - 6");
  Polynomial n("-x^4 + 3*x^2 - x + 6");
  Polynomial o("2*x^4 - 6*x^2 + 2*x - 12");
  EXPECT_EQ(m - n, o);

  Polynomial p("1/2*x^2 + 3/4*x - 1/3");
  Polynomial q("2/3*x^2 - 3/4*x + 1/6");
  Polynomial r("-1/6*x^2 + 3/2*x - 1/2");
  EXPECT_EQ(p - q, r);
}

TEST(PolynomialTest, MultiplicationByRational) {
  Polynomial a("3/2*x^5 - 4*x^3 + 1/2*x - 2");
  Polynomial b("3*x^5 - 8*x^3 + x - 4");
  a *= Rational("2");
  EXPECT_EQ(a, b);

  Polynomial c("x^3 - 2*x + 5");
  Polynomial d("-3*x^3 + 6*x - 15");
  c *= Rational("-3");
  EXPECT_EQ(c, d);

  Polynomial e("3*x^4 + x^2 - x");
  Polynomial f("3/2*x^4 + 1/2*x^2 - 1/2*x");
  e *= Rational("1/2");
  EXPECT_EQ(e, f);

  Polynomial g("2*x^3 + 3*x^2 - x + 7");
  Polynomial h("0");
  g *= Rational("0");
  EXPECT_EQ(g, h);

  Polynomial i("x^4 - 3*x^2 + x - 6");
  Polynomial j("x^4 - 3*x^2 + x - 6");
  EXPECT_EQ(i * Rational("1"), j);

  Polynomial k("1/2*x^2 + 3/4*x - 1/3");
  Polynomial l("-1/3*x^2 - 1/2*x + 2/9");
  EXPECT_EQ(k * Rational("-2/3"), l);
}

TEST(PolynomialTest, MultiplyByXPower) {
  Polynomial a("3/2*x^5 - 4*x^3 + 1/2*x - 2");
  Polynomial b("3/2*x^8 - 4*x^6 + 1/2*x^4 - 2*x^3");
  a.MultiplyByXPower(3);
  EXPECT_EQ(a, b);

  Polynomial c("x^3 - 2*x + 5");
  Polynomial d("x^5 - 2*x^3 + 5*x^2");
  c.MultiplyByXPower(2);
  EXPECT_EQ(c, d);

  Polynomial e("3*x^4 + x^2 - x");
  Polynomial f("3*x^6 + x^4 - x^3");
  e.MultiplyByXPower(2);
  EXPECT_EQ(e, f);

  Polynomial g("2*x^3 + 3*x^2 - x + 7");
  Polynomial h("2*x^3 + 3*x^2 - x + 7");
  g.MultiplyByXPower(0);
  EXPECT_EQ(g, h);

  Polynomial i("x^4 - 3*x^2 + x - 6");
  Polynomial j("x^7 - 3*x^5 + x^4 - 6*x^3");
  EXPECT_EQ(i.MultiplyByXPower(3), j);

  Polynomial k("1/2*x^2 + 3/4*x - 1/3");
  Polynomial l("1/2*x^7 + 3/4*x^6 - 1/3*x^5");
  EXPECT_EQ(k.MultiplyByXPower(5), l);
}

TEST(PolynomialTest, Multiplication) {
  Polynomial a("3/2*x^2 - 2*x + 1");
  Polynomial b("x + 1");
  Polynomial c("3/2*x^3 - 1/2*x^2 - x + 1");
  a *= b;
  EXPECT_EQ(a, c);

  Polynomial d("x^2 + 2*x + 1");
  Polynomial e("x + 3");
  Polynomial f("x^3 + 5*x^2 + 7*x + 3");
  d *= e;
  EXPECT_EQ(d, f);

  Polynomial g("2*x^2 - x + 3");
  Polynomial h("x^2 + 1");
  Polynomial i("2*x^4 - x^3 + 5*x^2 - x + 3");
  g *= h;
  EXPECT_EQ(g, i);

  Polynomial j("x^3 + 3");
  Polynomial k("0");
  Polynomial l("0");
  j *= k;
  EXPECT_EQ(j, l);

  Polynomial m("1/2*x + 1");
  Polynomial n("2*x^2 - x + 1/2");
  Polynomial o("x^3 + 3/2*x^2 - 3/4*x + 1/2");
  EXPECT_EQ(m * n, o);

  Polynomial p("x + 2");
  Polynomial q("x - 2");
  Polynomial r("x^2 - 4");
  EXPECT_EQ(p * q, r);
}

TEST(PolynomialTest, DivisionQuotient) {
  Polynomial a("x^2 + 2*x + 1");
  Polynomial b("x + 1");
  Polynomial c("x + 1");
  a /= b;
  EXPECT_EQ(a, c);

  Polynomial d("x^3 + 3*x^2 + 3*x + 1");
  Polynomial e("x + 1");
  Polynomial f("x^2 + 2*x + 1");
  d /= e;
  EXPECT_EQ(d, f);

  Polynomial g("x^4 - 2*x^3 + x^2 + 3*x - 1");
  Polynomial h("x^2 - 1");
  Polynomial i("x^2 - 2*x + 2");
  g /= h;
  EXPECT_EQ(g, i);

  Polynomial j("2*x^3 + 3*x^2 + 4*x + 5");
  Polynomial k("x + 2");
  Polynomial l("2*x^2 - x + 6");
  EXPECT_EQ(j / k, l);

  Polynomial m("x + 2");
  Polynomial n("0");
  EXPECT_THROW(m / n, std::invalid_argument);
}

TEST(PolynomialTest, DivisionRemainder) {
  Polynomial a("x^3 + 3*x^2 + 3*x + 1");
  Polynomial b("x + 1");
  Polynomial c("0");
  a %= b;
  EXPECT_EQ(a, c);

  Polynomial d("x^4 - 2*x^3 + x^2 + 3*x - 1");
  Polynomial e("x^2 - 1");
  Polynomial f("x + 1");
  d %= e;
  EXPECT_EQ(d, f);

  Polynomial g("2*x^3 + 3*x^2 + 4*x + 5");
  Polynomial h("x + 2");
  Polynomial i("-7");
  g %= h;
  EXPECT_EQ(g, i);

  Polynomial j("3*x^5 - x^4 + 2*x^3 - x + 4");
  Polynomial k("x^2 + 1");
  Polynomial l("3");
  j %= k;
  EXPECT_EQ(j, l);

  Polynomial m("5*x^3 - 3*x^2 + 2");
  Polynomial n("x^2 + 1");
  Polynomial o("-5*x + 5");
  m %= n;
  EXPECT_EQ(m, o);
}

TEST(PolynomialTest, GreatestCommonDivisor) {
  Polynomial a("x^3 - 3*x^2 + 3*x - 1");
  Polynomial b("x^2 - 2*x + 1");
  Polynomial c("x^2 - 2*x + 1");
  EXPECT_EQ(Polynomial::GreatestCommonDivisor(a, b), c);

  Polynomial d("x^4 - 4*x^3 + 6*x^2 - 4*x + 1");
  Polynomial e("x^2 - 2*x + 1");
  Polynomial f("x^2 - 2*x + 1");
  EXPECT_EQ(Polynomial::GreatestCommonDivisor(d, e), f);

  Polynomial g("x^3 + x + 1");
  Polynomial h("x^2 + x + 1");
  Polynomial i("1");
  const Polynomial& polynomial = Polynomial::GreatestCommonDivisor(g, h);
  EXPECT_EQ(polynomial, i);

  Polynomial j("x^2 + 4*x + 4");
  Polynomial k("2");
  Polynomial l("1");
  EXPECT_EQ(Polynomial::GreatestCommonDivisor(j, k), l);

  Polynomial m("x^3 - x");
  Polynomial n("3*x^2 - 1");
  Polynomial o("1");
  EXPECT_EQ(Polynomial::GreatestCommonDivisor(m, n), o);

  Polynomial p("0");
  Polynomial q("0");
  Polynomial r("1");
  EXPECT_EQ(Polynomial::GreatestCommonDivisor(p, q), r);

  Polynomial s("x^2 - x");
  Polynomial t("0");
  Polynomial u("x^2 - x");
  EXPECT_EQ(Polynomial::GreatestCommonDivisor(s, t), u);
}

TEST(PolynomialTest, Derivative) {
  Polynomial pol1({{Natural(0), Rational(Integer(1), Natural(1))},
                   {Natural(1), Rational(Integer(2), Natural(1))},
                   {Natural(2), Rational(Integer(3), Natural(1))}});
  Polynomial pol2({
      {Natural(0), Rational(Integer(2), Natural(1))},
      {Natural(1), Rational(Integer(6), Natural(1))},
  });
  pol1 = pol1.Derivative(pol1);
  EXPECT_EQ(pol1.GetDegree(), pol2.GetDegree());

  Polynomial pol3({{Natural(0), Rational(Integer(10), Natural(1))},
                   {Natural(1), Rational(Integer(16), Natural(1))}});
  Polynomial pol4({{Natural(0), Rational(Integer(16), Natural(1))}});
  pol3 = pol3.Derivative(pol3);
  EXPECT_EQ(pol3.GetDegree(), pol4.GetDegree());

  Polynomial pol5({{Natural(1), Rational(Integer(6), Natural(1))},
                   {Natural(12), Rational(Integer(2), Natural(1))}});
  Polynomial pol6({{Natural(0), Rational(Integer(6), Natural(1))},
                   {Natural(11), Rational(Integer(24), Natural(1))}});
  pol5 = pol5.Derivative(pol5);
  EXPECT_EQ(pol5.GetDegree(), pol6.GetDegree());

  Polynomial pol7({{Natural(10), Rational(Integer(264), Natural(1))}});
  pol5 = pol5.Derivative(pol5);
  EXPECT_EQ(pol5.GetDegree(), pol7.GetDegree());
}

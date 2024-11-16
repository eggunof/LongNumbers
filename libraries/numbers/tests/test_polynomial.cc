#include <gtest/gtest.h>

#include "polynomial.h"

TEST(PolynomialTest, StringToPolynomial) {
  std::vector<std::pair<std::string, std::map<Natural, Rational, Comparator>>>
      test_cases = {
          {"3/2*x^5 - 4*x^3 + 1/2*x - 2",
           {{Natural("5"), Rational("3/2")},
            {Natural("3"), Rational("-4")},
            {Natural("1"), Rational("1/2")},
            {Natural("0"), Rational("-2")}}},
          {"5/3*x^4 + 7*x + 2",
           {{Natural("4"), Rational("5/3")},
            {Natural("1"), Rational("7")},
            {Natural("0"), Rational("2")}}},
          {"-3*x^4 + 6/5*x^2 - x + 1/3",
           {{Natural("4"), Rational("-3")},
            {Natural("2"), Rational("6/5")},
            {Natural("1"), Rational("-1")},
            {Natural("0"), Rational("1/3")}}},
          {"4*x^7 + 5 - x^5 + 1/2*x^2 - 7/8",
           {{Natural("7"), Rational("4")},
            {Natural("5"), Rational("-1")},
            {Natural("2"), Rational("1/2")},
            {Natural("0"), Rational("33/8")}}},
          {"2*x^3 - 3*x^3 + x + x - 1",
           {{Natural("3"), Rational("-1")},
            {Natural("1"), Rational("2")},
            {Natural("0"), Rational("-1")}}},
          {"3*x^3 - 3*x^3 + x - x + 2 - 2", {}},
          {"7*x^3 + 1/2*x - 3",
           {{Natural("3"), Rational("7")},
            {Natural("1"), Rational("1/2")},
            {Natural("0"), Rational("-3")}}},
          {"x^5 - x^2",
           {{Natural("5"), Rational("1")}, {Natural("2"), Rational("-1")}}}};

  for (const auto& test_case : test_cases) {
    Polynomial p(test_case.first);
    EXPECT_EQ(p, Polynomial(test_case.second));
  }
}

TEST(PolynomialTest, Addition) {
  std::vector<std::tuple<std::string, std::string, std::string>> test_cases = {
      {"3/2*x^5 - 4*x^3 + 1/2*x - 2", "2*x^4 + x^3 - 1/2*x + 3",
       "3/2*x^5 + 2*x^4 - 3*x^3 + 1"},
      {"x^3 - 2*x + 5", "2*x^3 + 3*x - 1", "3*x^3 + x + 4"},
      {"3*x^4 + x^2 - x", "-3*x^4 - x^2 + 2*x + 5", "x + 5"},
      {"2*x^3 + 3*x^2 - x + 7", "0", "2*x^3 + 3*x^2 - x + 7"},
      {"x^4 - 3*x^2 + x - 6", "-x^4 + 3*x^2 - x + 6", "0"},
      {"1/2*x^2 + 3/4*x - 1/3", "2/3*x^2 - 3/4*x + 1/6", "7/6*x^2 - 1/6"}};

  for (const auto& test_case : test_cases) {
    Polynomial a(std::get<0>(test_case));
    Polynomial b(std::get<1>(test_case));
    Polynomial expected(std::get<2>(test_case));
    a += b;
    EXPECT_EQ(a, expected);
  }
}

TEST(PolynomialTest, Subtraction) {
  std::vector<std::tuple<std::string, std::string, std::string>> test_cases = {
      {"3/2*x^5 - 4*x^3 + 1/2*x - 2", "2*x^4 + x^3 - 1/2*x + 3",
       "3/2*x^5 - 2*x^4 - 5*x^3 + x - 5"},
      {"x^3 - 2*x + 5", "2*x^3 + 3*x - 1", "-x^3 - 5*x + 6"},
      {"3*x^4 + x^2 - x", "3*x^4 + x^2 - 2*x - 5", "x + 5"},
      {"2*x^3 + 3*x^2 - x + 7", "0", "2*x^3 + 3*x^2 - x + 7"},
      {"x^4 - 3*x^2 + x - 6", "-x^4 + 3*x^2 - x + 6",
       "2*x^4 - 6*x^2 + 2*x - 12"},
      {"1/2*x^2 + 3/4*x - 1/3", "2/3*x^2 - 3/4*x + 1/6",
       "-1/6*x^2 + 3/2*x - 1/2"}};

  for (const auto& test_case : test_cases) {
    Polynomial a(std::get<0>(test_case));
    Polynomial b(std::get<1>(test_case));
    Polynomial expected(std::get<2>(test_case));
    a -= b;
    EXPECT_EQ(a, expected);
  }
}

TEST(PolynomialTest, MultiplicationByRational) {
  std::vector<std::tuple<std::string, std::string, std::string>> test_cases = {
      {"3/2*x^5 - 4*x^3 + 1/2*x - 2", "2", "3*x^5 - 8*x^3 + x - 4"},
      {"x^3 - 2*x + 5", "-3", "-3*x^3 + 6*x - 15"},
      {"3*x^4 + x^2 - x", "1/2", "3/2*x^4 + 1/2*x^2 - 1/2*x"},
      {"2*x^3 + 3*x^2 - x + 7", "0", "0"},
      {"x^4 - 3*x^2 + x - 6", "1", "x^4 - 3*x^2 + x - 6"},
      {"1/2*x^2 + 3/4*x - 1/3", "-2/3", "-1/3*x^2 - 1/2*x + 2/9"}};

  for (const auto& test_case : test_cases) {
    Polynomial a(std::get<0>(test_case));
    Polynomial expected(std::get<2>(test_case));
    a *= Rational(std::get<1>(test_case));
    EXPECT_EQ(a, expected);
  }
}

TEST(PolynomialTest, MultiplyByXPower) {
  std::vector<std::tuple<std::string, uint32_t, std::string>> test_cases = {
      {"3/2*x^5 - 4*x^3 + 1/2*x - 2", 3, "3/2*x^8 - 4*x^6 + 1/2*x^4 - 2*x^3"},
      {"x^3 - 2*x + 5", 2, "x^5 - 2*x^3 + 5*x^2"},
      {"3*x^4 + x^2 - x", 2, "3*x^6 + x^4 - x^3"},
      {"2*x^3 + 3*x^2 - x + 7", 0, "2*x^3 + 3*x^2 - x + 7"},
      {"x^4 - 3*x^2 + x - 6", 3, "x^7 - 3*x^5 + x^4 - 6*x^3"},
      {"1/2*x^2 + 3/4*x - 1/3", 5, "1/2*x^7 + 3/4*x^6 - 1/3*x^5"}};

  for (const auto& test_case : test_cases) {
    Polynomial a(std::get<0>(test_case));
    Polynomial expected(std::get<2>(test_case));
    a.MultiplyByXPower(std::get<1>(test_case));
    EXPECT_EQ(a, expected);
  }
}

TEST(PolynomialTest, Multiplication) {
  std::vector<std::tuple<std::string, std::string, std::string>> test_cases = {
      {"3/2*x^2 - 2*x + 1", "x + 1", "3/2*x^3 - 1/2*x^2 - x + 1"},
      {"x^2 + 2*x + 1", "x + 3", "x^3 + 5*x^2 + 7*x + 3"},
      {"2*x^2 - x + 3", "x^2 + 1", "2*x^4 - x^3 + 5*x^2 - x + 3"},
      {"x^3 + 3", "0", "0"},
      {"1/2*x + 1", "2*x^2 - x + 1/2", "x^3 + 3/2*x^2 - 3/4*x + 1/2"},
      {"x + 2", "x - 2", "x^2 - 4"}};

  for (const auto& test_case : test_cases) {
    Polynomial a(std::get<0>(test_case));
    Polynomial b(std::get<1>(test_case));
    Polynomial expected(std::get<2>(test_case));
    EXPECT_EQ(a * b, expected);
  }
}

TEST(PolynomialTest, DivisionQuotient) {
  std::vector<std::tuple<std::string, std::string, std::string>> test_cases = {
      {"x^2 + 2*x + 1", "x + 1", "x + 1"},
      {"x^3 + 3*x^2 + 3*x + 1", "x + 1", "x^2 + 2*x + 1"},
      {"x^4 - 2*x^3 + x^2 + 3*x - 1", "x^2 - 1", "x^2 - 2*x + 2"},
      {"2*x^3 + 3*x^2 + 4*x + 5", "x + 2", "2*x^2 - x + 6"},
      {"x + 2", "0", "Invalid Argument"}};

  for (const auto& test_case : test_cases) {
    Polynomial a(std::get<0>(test_case));
    Polynomial b(std::get<1>(test_case));
    try {
      EXPECT_EQ(a / b, Polynomial(std::get<2>(test_case)));
    } catch (const std::invalid_argument&) {
      EXPECT_EQ(std::get<2>(test_case), "Invalid Argument");
    }
  }
}

TEST(PolynomialTest, DivisionRemainder) {
  std::vector<std::tuple<std::string, std::string, std::string>> test_cases = {
      {"x^3 + 3*x^2 + 3*x + 1", "x + 1", "0"},
      {"x^4 - 2*x^3 + x^2 + 3*x - 1", "x^2 - 1", "x + 1"},
      {"2*x^3 + 3*x^2 + 4*x + 5", "x + 2", "-7"},
      {"3*x^5 - x^4 + 2*x^3 - x + 4", "x^2 + 1", "3"},
      {"5*x^3 - 3*x^2 + 2", "x^2 + 1", "-5*x + 5"}};

  for (const auto& test_case : test_cases) {
    Polynomial a(std::get<0>(test_case));
    Polynomial b(std::get<1>(test_case));
    Polynomial expected(std::get<2>(test_case));
    a %= b;
    EXPECT_EQ(a, expected);
  }
}

TEST(PolynomialTest, GreatestCommonDivisor) {
  std::vector<std::tuple<std::string, std::string, std::string>> test_cases = {
      {"x^3 - 3*x^2 + 3*x - 1", "x^2 - 2*x + 1", "x^2 - 2*x + 1"},
      {"x^4 - 4*x^3 + 6*x^2 - 4*x + 1", "x^2 - 2*x + 1", "x^2 - 2*x + 1"},
      {"x^3 + x + 1", "x^2 + x + 1", "1"},
      {"x^2 + 4*x + 4", "2", "1"},
      {"x^3 - x", "3*x^2 - 1", "1"},
      {"0", "0", "1"},
      {"x^2 - x", "0", "x^2 - x"}};

  for (const auto& test_case : test_cases) {
    Polynomial a(std::get<0>(test_case));
    Polynomial b(std::get<1>(test_case));
    Polynomial expected(std::get<2>(test_case));
    EXPECT_EQ(Polynomial::GreatestCommonDivisor(a, b), expected);
  }
}

TEST(PolynomialTest, Derivative) {
  std::vector<std::tuple<std::string, std::string>> test_cases = {
      {"3*x^5 - 2*x^3 + x - 4", "15*x^4 - 6*x^2 + 1"},
      {"x^4 - 3*x^2 + 2*x", "4*x^3 - 6*x + 2"},
      {"7*x^3 - 5*x + 1", "21*x^2 - 5"},
      {"x^2 - x + 1", "2*x - 1"},
      {"5*x^2", "10*x"},
      {"x", "1"},
      {"7", "0"}};

  for (const auto& test_case : test_cases) {
    Polynomial a(std::get<0>(test_case));
    Polynomial expected(std::get<1>(test_case));
    EXPECT_EQ(Polynomial::Derivative(a), expected);
  }
}

TEST(PolynomialTest, ToIntegerCoefficients) {
  std::vector<std::tuple<std::string, std::string, std::string>> test_cases = {
      {"1/2*x^3 - 3/4*x^2 + 5/6*x - 1/3", "6*x^3 - 9*x^2 + 10*x - 4", "1/12"},
      {"2/3*x^2 + 4/5*x - 7/10", "20*x^2 + 24*x - 21", "1/30"},
      {"3*x - 6", "x - 2", "3"},
      {"0", "0", "1"},
      {"1/4*x^5 + 3/8*x^3 - 9/16", "4*x^5 + 6*x^3 - 9", "1/16"},
      {"-5/7*x^2 + 6/14*x - 3/21", "5*x^2 - 3*x + 1", "-1/7"},
      {"1/2*x^4 - 1/3*x^3 + 1/4*x^2 - 1/6*x + 1/12",
       "6*x^4 - 4*x^3 + 3*x^2 - 2*x + 1", "1/12"}};

  for (const auto& test_case : test_cases) {
    Polynomial a(std::get<0>(test_case));
    Polynomial expected(std::get<1>(test_case));
    EXPECT_EQ(a.ToIntegerCoefficients(), Rational(std::get<2>(test_case)));
    EXPECT_EQ(a, expected);
  }
}

TEST(PolynomialTest, NormalizeRoots) {
  std::vector<std::tuple<std::string, std::string>> test_cases = {
      {"x^6 - 3*x^4 + 3*x^2 - 1", "x^2 - 1"},
      {"x^4 - 2*x^3 + x^2", "x^2 - x"},
      {"x^8 - 4*x^6 + 6*x^4 - 4*x^2 + 1", "x^2 - 1"},
      {"x^3 - x", "x^3 - x"},
      {"x^6 - 8*x^4 + 16*x^2", "x^3 - 4x"},
      {"x^3 - 2*x^2 + x", "x^2 - x"},
      {"x^4 - 2*x^3 + x^2", "x^2 - x"}};

  for (const auto& test_case : test_cases) {
    Polynomial a(std::get<0>(test_case));
    Polynomial expected(std::get<1>(test_case));
    EXPECT_EQ(Polynomial::NormalizeRoots(a), expected);
  }
}

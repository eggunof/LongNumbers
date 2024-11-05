
#ifndef LONGNUMBERS_SRC_MODULES_POLYNOMIAL_H_
#define LONGNUMBERS_SRC_MODULES_POLYNOMIAL_H_

#include <map>
#include "natural.h"
#include "rational.h"

struct Comparator {
  bool operator()(const Natural &first, const Natural &second) const {
    return first > second;
  }
};

class Polynomial {
 protected:
  std::map<Natural, Rational, Comparator> coefficients_;
 public:
  Polynomial() : coefficients_({{Natural("0"), Rational("0")}}) {}
  explicit Polynomial(const std::map<Natural, Rational, Comparator> &coefficients) : coefficients_(coefficients) {}
  Polynomial(const Polynomial &other) = default;
  Polynomial &operator=(const Polynomial &other) = default;

  [[nodiscard]] Natural GetDegree() const { return coefficients_.begin()->first; } // DEG_P_N
  [[nodiscard]] Rational GetLeadingCoefficient() const { return coefficients_.begin()->second; } // LED_P_N

  Polynomial operator+(const Polynomial &rhs) const; // ADD_PP_P
  Polynomial operator-(const Polynomial &rhs) const; // SUB_PP_P
  Polynomial operator*(const Rational &scalar) const; // MUL_PQ_P
  Polynomial operator*(const Polynomial &rhs) const; // MUL_PP_P
  Polynomial operator/(const Polynomial &rhs) const; // DIV_PP_P
  Polynomial operator%(const Polynomial &rhs) const; // MOD_PP_P

  Polynomial &operator+=(const Polynomial &rhs); // ADD_PP_P
  Polynomial &operator-=(const Polynomial &rhs); // SUB_PP_P
  Polynomial &operator*=(const Rational &scalar); // MUL_PQ_P
  Polynomial &operator*=(const Polynomial &rhs); // MUL_PP_P
  Polynomial &operator/=(const Polynomial &rhs); // DIV_PP_P
  Polynomial &operator%=(const Polynomial &rhs); // MOD_PP_P

  Polynomial &MultiplyByXPower(uint32_t k); // MUL_Pxk_P

  Rational ToIntegerCoefficients(const Polynomial &polynomial); // FAC_P_Q

  static Polynomial GreatestCommonDivisor(const Polynomial &first, const Polynomial &second); // GCD_PP_P
  static Polynomial Derivative(const Polynomial &polynomial); // DER_P_P
  static Polynomial NormalizeRoots(const Polynomial &polynomial); // NMR_P_P
};

#endif //LONGNUMBERS_SRC_MODULES_POLYNOMIAL_H_
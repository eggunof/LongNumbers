
#ifndef NUMBERS_POLYNOMIAL_H_
#define NUMBERS_POLYNOMIAL_H_

#include <map>
#include <stdexcept>

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
  Polynomial() = default;
  explicit Polynomial(
      const std::map<Natural, Rational, Comparator> &coefficients)
      : coefficients_(coefficients) {}
  explicit Polynomial(const std::string &string);
  Polynomial(const Natural &degree, const Rational &coefficient)
      : coefficients_({{degree, coefficient}}) {}
  Polynomial(const Polynomial &other) = default;
  Polynomial &operator=(const Polynomial &other) = default;

  [[nodiscard]] Natural GetDegree() const;               // DEG_P_N
  [[nodiscard]] Rational GetLeadingCoefficient() const;  // LED_P_N

  bool operator==(const Polynomial &rhs) const;
  bool operator!=(const Polynomial &rhs) const;

  Polynomial operator-() const;
  Polynomial operator+(const Polynomial &rhs) const;   // ADD_PP_P
  Polynomial operator-(const Polynomial &rhs) const;   // SUB_PP_P
  Polynomial operator*(const Rational &scalar) const;  // MUL_PQ_P
  Polynomial operator*(const Polynomial &rhs) const;   // MUL_PP_P
  Polynomial operator/(const Polynomial &rhs) const;   // DIV_PP_P
  Polynomial operator%(const Polynomial &rhs) const;   // MOD_PP_P

  Polynomial operator-();
  Polynomial &operator+=(const Polynomial &rhs);   // ADD_PP_P
  Polynomial &operator-=(const Polynomial &rhs);   // SUB_PP_P
  Polynomial &operator*=(const Rational &scalar);  // MUL_PQ_P
  Polynomial &operator*=(const Polynomial &rhs);   // MUL_PP_P
  Polynomial &operator/=(const Polynomial &rhs);   // DIV_PP_P
  Polynomial &operator%=(const Polynomial &rhs);   // MOD_PP_P

  Polynomial &MultiplyByXPower(uint32_t k);                     // MUL_Pxk_P
  [[nodiscard]] Polynomial MultiplyByXPower(uint32_t k) const;  // MUL_Pxk_P

  Rational ToIntegerCoefficients(const Polynomial &polynomial);  // FAC_P_Q

  static Polynomial GreatestCommonDivisor(
      const Polynomial &first, const Polynomial &second);          // GCD_PP_P
  static Polynomial Derivative(const Polynomial &polynomial);      // DER_P_P
  static Polynomial NormalizeRoots(const Polynomial &polynomial);  // NMR_P_P

  explicit operator std::string() const;
};

#endif  // NUMBERS_POLYNOMIAL_H_

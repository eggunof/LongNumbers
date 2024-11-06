
#ifndef LONGNUMBERS_SRC_MODULES_RATIONAL_H_
#define LONGNUMBERS_SRC_MODULES_RATIONAL_H_

#include "integer.h"
#include "natural.h"

class Rational {
 protected:
  Integer numerator_;
  Natural denominator_;
 public:
  Rational() : numerator_(0), denominator_(1) {}
  Rational(const Integer &numerator, const Natural &denominator);
  explicit Rational(const std::string &string);
  Rational(const Rational &other) = default;
  Rational &operator=(const Rational &other) = default;

  explicit Rational(const Integer &integer) : numerator_(integer), denominator_(Natural()) {} // TRANS_Z_Q
  static Integer ToInteger(const Rational &rational); // TRANS_Q_Z

  Rational &Reduce(); // RED_Q_Q
  bool IsInteger(); // INT_Q_B

  Rational operator+(const Rational &rhs) const; // ADD_QQ_Q
  Rational operator-(const Rational &rhs) const; // SUB_QQ_Q
  Rational operator*(const Rational &rhs) const; // MUL_QQ_Q
  Rational operator/(const Rational &rhs) const; // DIV_QQ_Q

  Rational operator+=(const Rational &rhs); // ADD_QQ_Q
  Rational operator-=(const Rational &rhs); // SUB_QQ_Q
  Rational operator*=(const Rational &rhs); // MUL_QQ_Q
  Rational operator/=(const Rational &rhs); // DIV_QQ_Q
};

#endif //LONGNUMBERS_SRC_MODULES_RATIONAL_H_

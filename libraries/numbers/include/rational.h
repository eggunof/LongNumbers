
#ifndef NUMBERS_RATIONAL_H_
#define NUMBERS_RATIONAL_H_

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

  explicit Rational(const Integer &integer);  // TRANS_Z_Q
  explicit operator Integer() const;          // TRANS_Q_Z
  Rational &Reduce();                         // RED_Q_Q
  bool IsInteger();                           // INT_Q_B

  bool operator==(const Rational &rhs) const;
  bool operator!=(const Rational &rhs) const;
  bool operator<(const Rational &rhs) const;
  bool operator>(const Rational &rhs) const;
  bool operator<=(const Rational &rhs) const;
  bool operator>=(const Rational &rhs) const;

  Rational &operator-();
  Rational operator+=(const Rational &rhs);  // ADD_QQ_Q
  Rational operator-=(const Rational &rhs);  // SUB_QQ_Q
  Rational operator*=(const Rational &rhs);  // MUL_QQ_Q
  Rational operator/=(const Rational &rhs);  // DIV_QQ_Q

  Rational operator-() const;
  Rational operator+(const Rational &rhs) const;  // ADD_QQ_Q
  Rational operator-(const Rational &rhs) const;  // SUB_QQ_Q
  Rational operator*(const Rational &rhs) const;  // MUL_QQ_Q
  Rational operator/(const Rational &rhs) const;  // DIV_QQ_Q

  explicit operator std::string() const;
};

#endif  // NUMBERS_RATIONAL_H_


#ifndef NUMBERS_INTEGER_H_
#define NUMBERS_INTEGER_H_

#include "natural.h"

enum class Sign { NEGATIVE = -1, ZERO = 0, POSITIVE = 1 };

class Integer {
 protected:
  Natural natural_;
  Sign sign_;

 public:
  Integer() : natural_(), sign_(Sign::ZERO) {}
  Integer(const Natural &natural, Sign sign);
  Integer(const std::vector<Digit> &digits, Sign sign)
      : Integer(Natural(digits), sign) {}
  explicit Integer(const std::string &string);
  explicit Integer(int32_t number) : Integer(std::to_string(number)) {}
  Integer(const Integer &other) = default;
  Integer &operator=(const Integer &other) = default;

  explicit Integer(const Natural &natural);              // TRANS_N_Z
  explicit operator Natural() const;                     // TRANS_Z_N
  static Integer AbsoluteValue(const Integer &integer);  // ABS_Z_Z

  [[nodiscard]] Sign GetSign() const { return sign_; }  // SGN_Z_D

  bool operator==(const Integer &rhs) const;
  bool operator!=(const Integer &rhs) const;
  bool operator<(const Integer &rhs) const;
  bool operator>(const Integer &rhs) const;
  bool operator<=(const Integer &rhs) const;
  bool operator>=(const Integer &rhs) const;

  Integer &operator-();                     // MUL_ZM_Z
  Integer &operator+=(const Integer &rhs);  // ADD_ZZ_Z
  Integer &operator-=(const Integer &rhs);  // SUB_ZZ_Z
  Integer &operator*=(const Integer &rhs);  // MUL_ZZ_Z
  Integer &operator/=(const Integer &rhs);  // DIV_ZZ_Z
  Integer &operator%=(const Integer &rhs);  // MOD_ZZ_Z

  Integer operator-() const;                    // MUL_ZM_Z
  Integer operator+(const Integer &rhs) const;  // ADD_ZZ_Z
  Integer operator-(const Integer &rhs) const;  // SUB_ZZ_Z
  Integer operator*(const Integer &rhs) const;  // MUL_ZZ_Z
  Integer operator/(const Integer &rhs) const;  // DIV_ZZ_Z
  Integer operator%(const Integer &rhs) const;  // MOD_ZZ_Z

  static Integer GreatestCommonDivisor(const Integer &first,
                                       const Integer &second);
  static Integer LeastCommonMultiple(const Integer &first,
                                     const Integer &second);

  explicit operator std::string() const;
};

#endif  // NUMBERS_INTEGER_H_

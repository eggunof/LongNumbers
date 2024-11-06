
#ifndef LONGNUMBERS_SRC_MODULES_INTEGER_H_
#define LONGNUMBERS_SRC_MODULES_INTEGER_H_

#include "natural.h"

enum class Sign {
  NEGATIVE = -1,
  ZERO = 0,
  POSITIVE = 1
};

class Integer : public Natural {
 protected:
  Sign sign_;
 public:
  Integer() : Natural(), sign_(Sign::ZERO) {}
  Integer(const std::vector<Digit> &digits, Sign sign);
  explicit Integer(const std::string &string);
  explicit Integer(int32_t number) : Integer(std::to_string(number)) {}
  Integer(const Integer &other) = default;
  Integer &operator=(const Integer &other) = default;

  explicit Integer(const Natural &natural); // TRANS_N_Z
  static Natural ToNatural(const Integer &integer); // TRANS_Z_N
  static Integer AbsoluteValue(const Integer &integer); // ABS_Z_Z

  [[nodiscard]] Sign GetSign() const { return sign_; } // SGN_Z_D

  Integer operator-() const; // MUL_ZM_Z
  Integer &operator-(); // MUL_ZM_Z

  Integer operator+(const Integer &rhs) const; // ADD_ZZ_Z
  Integer operator-(const Integer &rhs) const; // SUB_ZZ_Z
  Integer operator*(const Integer &rhs) const; // MUL_ZZ_Z
  Integer operator/(const Integer &rhs) const; // DIV_ZZ_Z
  Integer operator%(const Integer &rhs) const; // MOD_ZZ_Z

  Integer &operator+=(const Integer &rhs); // ADD_ZZ_Z
  Integer &operator-=(const Integer &rhs); // SUB_ZZ_Z
  Integer &operator*=(const Integer &rhs); // MUL_ZZ_Z
  Integer &operator/=(const Integer &rhs); // DIV_ZZ_Z
  Integer &operator%=(const Integer &rhs); // MOD_ZZ_Z
};

#endif //LONGNUMBERS_SRC_MODULES_INTEGER_H_
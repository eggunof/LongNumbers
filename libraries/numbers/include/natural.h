
#ifndef LONGNUMBERS_SRC_MODULES_NATURAL_H_
#define LONGNUMBERS_SRC_MODULES_NATURAL_H_

#include <cstdint>
#include <vector>
#include <string>

typedef uint8_t Digit;

enum class Comparison {
  EQUAL = 0,
  LESS = 1,
  GREATER = 2
};

class Natural {
 protected:
  std::vector<Digit> digits_;
 public:
  Natural() : digits_(1, 0) {}
  explicit Natural(const std::vector<Digit> &digits);
  explicit Natural(const std::string &string);
  explicit Natural(uint32_t number) : Natural(std::to_string(number)) {}
  Natural(const Natural &other) = default;
  Natural &operator=(const Natural &other) = default;

  static Comparison Compare(const Natural &first, const Natural &second); // COM_NN_D
  bool operator==(const Natural &rhs) const; // COM_NN_D
  bool operator!=(const Natural &rhs) const; // COM_NN_D
  bool operator<(const Natural &rhs) const; // COM_NN_D
  bool operator>(const Natural &rhs) const; // COM_NN_D
  bool operator<=(const Natural &rhs) const; // COM_NN_D
  bool operator>=(const Natural &rhs) const; // COM_NN_D

  [[nodiscard]] bool IsZero() const; // NZER_N_B

  Natural &operator++(); // ADD_1N_N
  Natural &operator++(int); // ADD_1N_N

  Natural operator+(const Natural &rhs) const; // ADD_NN_N
  Natural operator-(const Natural &rhs) const; // SUB_NN_N
  Natural operator*(Digit d) const; // MUL_ND_N
  Natural operator*(const Natural &rhs) const; // MUL_NN_N
  Natural operator/(const Natural &rhs) const; // DIV_NN_N
  Natural operator%(const Natural &rhs) const; // MOD_NN_N

  Natural &operator+=(const Natural &rhs); // ADD_NN_N
  Natural &operator-=(const Natural &rhs); // SUB_NN_N;
  Natural &operator*=(Digit d); // MUL_ND_N
  Natural &operator*=(const Natural &rhs); // MUL_NN_N
  Natural &operator/=(const Natural &rhs); // DIV_NN_N
  Natural &operator%=(const Natural &rhs); // MOD_NN_N

  Natural &SubtractMultiplied(const Natural &rhs, Digit d); // SUB_NDN_N
  Natural &MultiplyBy10Power(uint32_t k); // MUL_Nk_N
  Digit GetLeadingDigitAfterDivision(const Natural &rhs, uint32_t k); // DIV_NN_Dk

  static Natural GreatestCommonDivisor(const Natural &first, const Natural &second); // GCD_NN_N
  static Natural LeastCommonMultiple(const Natural &first, const Natural &second); // LCM_NN_N
};

#endif //LONGNUMBERS_SRC_MODULES_NATURAL_H_


#include "natural.h"

#include <stdexcept>

Natural::Natural(const std::vector<Digit> &digits) {
  if (digits.empty()) {
    throw std::invalid_argument("Invalid input: vector must not be empty");
  }
  digits_.reserve(digits.size());
  for (Digit digit : digits) {
    if (digit >= 10) {
      throw std::invalid_argument("Invalid input: digit must be less than 10");
    }
    if (!digits_.empty() || digit != 0) {
      digits_.push_back(digit);
    }
  }
  if (digits_.empty()) {
    digits_.push_back(0);
  }
  digits_.shrink_to_fit();
}

Natural::Natural(const std::string &string) {
  if (string.empty()) {
    throw std::invalid_argument(
        "Invalid input: string must contain at least one digit");
  }
  digits_.reserve(string.length());
  for (char digit : string) {
    Digit x = digit - '0';
    if (x >= 10) {
      throw std::invalid_argument(
          "Invalid input: non-digit character in string");
    }
    if (!digits_.empty() || x != 0) {
      digits_.push_back(x);
    }
  }
  if (digits_.empty()) {
    digits_.push_back(0);
  }
  digits_.shrink_to_fit();
}

Comparison Natural::Compare(const Natural &first, const Natural &second) {
  return Comparison::EQUAL;
}

bool Natural::operator==(const Natural &rhs) const { return false; }

bool Natural::operator!=(const Natural &rhs) const { return false; }

bool Natural::operator<(const Natural &rhs) const { return false; }

bool Natural::operator>(const Natural &rhs) const { return false; }

bool Natural::operator<=(const Natural &rhs) const { return false; }

bool Natural::operator>=(const Natural &rhs) const { return false; }

bool Natural::IsZero() const { return digits_.size() == 1 && digits_[0] == 0; }

Natural &Natural::operator++() { return *this; }

Natural &Natural::operator++(int) { return *this; }

Natural Natural::operator+(const Natural &rhs) const { return {}; }

Natural Natural::operator-(const Natural &rhs) const { return {}; }

Natural Natural::operator*(Digit d) const { return {}; }

Natural Natural::operator*(const Natural &rhs) const { return {}; }

Natural Natural::operator/(const Natural &rhs) const { return {}; }

Natural Natural::operator%(const Natural &rhs) const { return {}; }

Natural &Natural::operator+=(const Natural &rhs) { return *this; }

Natural &Natural::operator-=(const Natural &rhs) { return *this; }

Natural &Natural::operator*=(Digit d) { return *this; }

Natural &Natural::operator*=(const Natural &rhs) { return *this; }

Natural &Natural::operator/=(const Natural &rhs) { return *this; }

Natural &Natural::operator%=(const Natural &rhs) { return *this; }

Natural &Natural::SubtractMultiplied(const Natural &rhs, Digit d) {
  return *this;
}

Natural &Natural::MultiplyBy10Power(uint32_t k) { return *this; }

Digit Natural::GetLeadingDigitAfterDivision(const Natural &rhs, uint32_t k) {
  return {};
}

Natural Natural::GreatestCommonDivisor(const Natural &first,
                                       const Natural &second) {
  return {};
}

Natural Natural::LeastCommonMultiple(const Natural &first,
                                     const Natural &second) {
  return {};
}

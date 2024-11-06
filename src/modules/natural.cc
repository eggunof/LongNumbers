
#include "natural.h"

#include <stdexcept>

Natural::Natural(const std::string &string) {
  for (char digit : string) {
    Digit x = digit - '0';
    if (x >= 10) {
      throw std::invalid_argument("Invalid input: non-digit character");
    }
    if (!digits_.empty() || x != 0) {
      digits_.push_back(x);
    }
  }
  if (digits_.empty()) {
    digits_.push_back(0);
  }
}

Compare Natural::Compare(const Natural &first, const Natural &second) {
  return Compare::EQUAL;
}

bool Natural::operator==(const Natural &rhs) const {
  return false;
}

bool Natural::operator!=(const Natural &rhs) const {
  return false;
}

bool Natural::operator<(const Natural &rhs) const {
  return false;
}

bool Natural::operator>(const Natural &rhs) const {
  return false;
}

bool Natural::operator<=(const Natural &rhs) const {
  return false;
}

bool Natural::operator>=(const Natural &rhs) const {
  return false;
}

bool Natural::IsZero() const {
  return false;
}

Natural &Natural::operator++() {
  return *this;
}

Natural &Natural::operator++(int) {
  return *this;
}

Natural Natural::operator+(const Natural &rhs) const {
  return {};
}

Natural Natural::operator-(const Natural &rhs) const {
  return {};
}

Natural Natural::operator*(Digit d) const {
  return {};
}

Natural Natural::operator*(const Natural &rhs) const {
  return {};
}

Natural Natural::operator/(const Natural &rhs) const {
  return {};
}

Natural Natural::operator%(const Natural &rhs) const {
  return {};
}

Natural &Natural::operator+=(const Natural &rhs) {
  return *this;
}

Natural &Natural::operator-=(const Natural &rhs) {
  return *this;
}

Natural &Natural::operator*=(Digit d) {
  return *this;
}

Natural &Natural::operator*=(const Natural &rhs) {
  return *this;
}

Natural &Natural::operator/=(const Natural &rhs) {
  return *this;
}

Natural &Natural::operator%=(const Natural &rhs) {
  return *this;
}

Natural &Natural::SubtractMultiplied(const Natural &rhs, Digit d) {
  return *this;
}

Natural &Natural::MultiplyBy10Power(uint32_t k) {
  return *this;
}

Digit Natural::GetLeadingDigitAfterDivision(const Natural &rhs, uint32_t k) {
  return {};
}

Natural Natural::GreatestCommonDivisor(const Natural &first, const Natural &second) {
  return {};
}

Natural Natural::LeastCommonMultiple(const Natural &first, const Natural &second) {
  return {};
}

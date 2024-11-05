
#include "natural.h"

Natural::Natural(const std::string &string) {

}

uint8_t Natural::Compare(const Natural &first, const Natural &second) {
  return {};
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

Natural &Natural::operator--() {
  return *this;
}

Natural &Natural::operator--(int) {
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

Natural Natural::GreatestCommonDivisor(const Natural &first, const Natural &second) {
  return {};
}

Natural Natural::LeastCommonMultiple(const Natural &first, const Natural &second) {
  return {};
}

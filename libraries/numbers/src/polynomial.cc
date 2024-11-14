
#include "polynomial.h"

#include <regex>
#include <sstream>

Polynomial::Polynomial(std::string string) {
  std::regex term_regex(
      R"((((?:[+-]+\s*)?(?:(\d+\s*)(?:\/\s*\d+\s*)?)?)?\*?x(?:\^?\s*(\d+\s*))?)|((?:[+-]+\s*)?\d+\s*(?:\/\s*\d+\s*)?))");
  std::sregex_iterator term_begin(string.begin(), string.end(), term_regex),
      term_end;

  for (auto it = term_begin; it != term_end; ++it) {
    const std::smatch &match = *it;

    Rational coefficient;
    Natural degree;

    if (match[1].matched) {
      std::string coefficient_str = match[2].matched ? match[2].str() : "1";
      if (coefficient_str.find_first_not_of("+- ") == std::string::npos)
        coefficient_str += "1";
      coefficient = Rational(coefficient_str);
      std::string degree_str = match[4].matched ? match[4].str() : "1";
      degree = Natural(degree_str);
    } else if (match[5].matched) {
      coefficient = Rational(match[5].str());
      degree = Natural("0");
    }

    coefficients_[degree] += coefficient;

    if (coefficients_[degree] == Rational("0")) {
      coefficients_.erase(degree);
    }
  }
}

bool Polynomial::operator==(const Polynomial &rhs) const {
  return coefficients_ == rhs.coefficients_;
}

bool Polynomial::operator!=(const Polynomial &rhs) const {
  return !(rhs == *this);
}

// Сложение многочленов "+"
// Над модулем работала Варфоломеева Арина, гр. 3383
Polynomial Polynomial::operator+(const Polynomial &rhs) const {
  // Складываем копию текущего объекта
  Polynomial result = *this;
  result += rhs;
  return result;
}

// Вычитание многочленов
// Над модулем работала Солдунова Екатерина, гр. 3383
Polynomial Polynomial::operator-(const Polynomial &rhs) const { 
  Polynomial result = *this;
  result -= rhs;
  return result;
}

Polynomial Polynomial::operator*(const Rational &scalar) const { return {}; }

Polynomial Polynomial::operator*(const Polynomial &rhs) const { return {}; }

Polynomial Polynomial::operator/(const Polynomial &rhs) const { return {}; }

Polynomial Polynomial::operator%(const Polynomial &rhs) const { return {}; }

// Сложение многочленов "+="
// Над модулем работала Варфоломеева Арина, гр. 3383
Polynomial &Polynomial::operator+=(const Polynomial &rhs) {
  // Проходимся по коэффициентам правого многочлена
  for (auto &[degree, coefficient] : rhs.coefficients_) {
    // Складываем и проверяем, не стал ли коэффициент равным нулю
    if ((coefficients_[degree] += coefficient) == Rational("0")) {
      // Если стал, удаляем
      coefficients_.erase(degree);
    }
  }
  return *this;
}

// Вычитание многочленов
// Над модулем работала Солдунова Екатерина, гр. 3383
Polynomial &Polynomial::operator-=(const Polynomial &rhs) { 
  for (auto & coefficient : rhs.coefficients_) coefficients_[coefficient.first] -= coefficient.second;
  return *this; 
}

Polynomial &Polynomial::operator*=(const Rational &scalar) { return *this; }

Polynomial &Polynomial::operator*=(const Polynomial &rhs) { return *this; }

Polynomial &Polynomial::operator/=(const Polynomial &rhs) { return *this; }

Polynomial &Polynomial::operator%=(const Polynomial &rhs) { return *this; }

Polynomial &Polynomial::MultiplyByXPower(uint32_t k) { return *this; }

Rational Polynomial::ToIntegerCoefficients(const Polynomial &polynomial) {
  return {};
}

Polynomial Polynomial::GreatestCommonDivisor(const Polynomial &first,
                                             const Polynomial &second) {
  return {};
}

Polynomial Polynomial::Derivative(const Polynomial &polynomial) { return {}; }

Polynomial Polynomial::NormalizeRoots(const Polynomial &polynomial) {
  return {};
}

Polynomial::operator std::string() const {
  std::ostringstream result;
  bool first_monomial = true;
  for (auto &[degree, coefficient] : coefficients_) {
    if (coefficient != Rational("1") && coefficient != Rational("-1")) {
      if (!first_monomial && coefficient > Rational("0")) {
        result << "+";
      }
      result << std::string(coefficient);
      if (!degree.IsZero()) result << "*";
    } else if (coefficient == Rational("-1")) {
      result << "-";
      if (degree.IsZero()) result << "1";
    }
    if (!degree.IsZero()) {
      result << "x";
      if (degree != Natural("1")) {
        result << "^" << std::string(degree);
      }
    }
    first_monomial = false;
  }
  if (result.tellp() == 0) return "0";
  return result.str();
}

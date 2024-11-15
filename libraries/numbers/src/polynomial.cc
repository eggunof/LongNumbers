
#include "polynomial.h"

#include <regex>
#include <sstream>

Polynomial::Polynomial(const std::string &string) {
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

Natural Polynomial::GetDegree() const {
  if (coefficients_.begin() == coefficients_.end()) return Natural("0");
  return coefficients_.begin()->first;
}

Rational Polynomial::GetLeadingCoefficient() const {
  if (coefficients_.begin() == coefficients_.end()) return Rational("0");
  return coefficients_.begin()->second;
}

bool Polynomial::operator==(const Polynomial &rhs) const {
  return coefficients_ == rhs.coefficients_;
}

bool Polynomial::operator!=(const Polynomial &rhs) const {
  return !(rhs == *this);
}

Polynomial Polynomial::operator-() const {
  Polynomial result = *this;
  return -result;
}

// Сложение многочленов "+"
// Над модулем работала Варфоломеева Арина, гр. 3383
Polynomial Polynomial::operator+(const Polynomial &rhs) const {
  // Складываем копию текущего объекта
  Polynomial result = *this;
  result += rhs;
  return result;
}

// Вычитание многочленов "-"
// Над модулем работала Солдунова Екатерина, гр. 3383
Polynomial Polynomial::operator-(const Polynomial &rhs) const {
  // Вычитаем копию текущего объекта
  Polynomial result = *this;
  result -= rhs;
  return result;
}

// Умножение многочлена на рациональное "*"
// Над модулем работала Кадникова Анна, гр. 3384
Polynomial Polynomial::operator*(const Rational &scalar) const {
  // Умножаем копию текущего объекта
  Polynomial result = *this;
  result *= scalar;
  return result;
}

// Умножение многочленов "*"
// Над модулем работала Дмитриева Дарья, гр. 3383
Polynomial Polynomial::operator*(const Polynomial &rhs) const {
  // Умножаем копию текущего объекта
  Polynomial result = *this;
  result *= rhs;
  return result;
}

// Частное от деления многочленов "/"
// Над модулем работала Солдунова Екатерина, гр. 3383
Polynomial Polynomial::operator/(const Polynomial &rhs) const {
  Polynomial result = *this;
  result /= rhs;
  return result;
}

// Остаток от деления многочленов "%="
// Над модулем работала Дмитриева Дарья, гр. 3383
Polynomial Polynomial::operator%(const Polynomial &rhs) const {
  Polynomial result = *this;
  result %= rhs;
  return result;
}

Polynomial Polynomial::operator-() {
  for (auto &[_, coefficient] : coefficients_) {
    -coefficient;
  }
  return *this;
}

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

// Вычитание многочленов "-="
// Над модулем работала Солдунова Екатерина, гр. 3383
Polynomial &Polynomial::operator-=(const Polynomial &rhs) {
  // Применяем сложение с противоположным знаком
  *this += -rhs;
  return *this;
}

// Умножение многочлена на рациональное "*="
// Над модулем работала Кадникова Анна, гр. 3384
Polynomial &Polynomial::operator*=(const Rational &scalar) {
  if (scalar == Rational("0")) {
    coefficients_ = {};
    return *this;
  }
  // Пройдёмся по коэффициентам многочлена, умножая каждый на скаляр
  for (auto &[_, coefficient] : coefficients_) {
    coefficient *= scalar;
  }

  return *this;
}

// Умножение многочленов "*="
// Над модулем работала Дмитриева Дарья, гр. 3383
Polynomial &Polynomial::operator*=(const Polynomial &rhs) {
  std::map<Natural, Rational, Comparator> result;
  // Перебираем все коэффициенты текущего многочлена
  for (const auto &[lhs_deg, lhs_coefficient] : coefficients_) {
    // Перебираем все коэффициенты многочлена rhs
    for (const auto &[rhs_deg, rhs_coefficient] : rhs.coefficients_) {
      // Складываем произведения коэффициентов при одинаковых степенях
      auto new_degree = lhs_deg + rhs_deg;
      auto new_coefficient = lhs_coefficient * rhs_coefficient;
      if ((result[new_degree] += new_coefficient) == Rational("0")) {
        result.erase(new_degree);
      }
    }
  }
  coefficients_ = std::move(result);
  return *this;
}

// Частное от деления многочленов "/="
// Над модулем работала Солдунова Екатерина, гр. 3383
Polynomial &Polynomial::operator/=(const Polynomial &rhs) {
  Polynomial result;
  while (!coefficients_.empty() && GetDegree() >= rhs.GetDegree()) {
    // Делим старшие мономы
    Polynomial monomial(GetDegree() - rhs.GetDegree(),
                        GetLeadingCoefficient() / rhs.GetLeadingCoefficient());
    // Прибавляем к результату
    result += monomial;
    // Вычитаем из делимого произведение найденного монома и делителя
    *this -= rhs * monomial;
  }
  *this = result;
  return *this;
}

// Остаток от деления многочленов "%="
// Над модулем работала Дмитриева Дарья, гр. 3383
Polynomial &Polynomial::operator%=(const Polynomial &rhs) {
  // Вычисляем неполное частное
  Polynomial quotient = *this / rhs;
  // Вычитаем из делимого неполное частное, умноженное на делитель
  *this -= rhs * quotient;
  return *this;
}

// Умножение многочлена на x^k
// Над модулем работала Майская Вероника, гр. 3384
Polynomial &Polynomial::MultiplyByXPower(uint32_t k) {
  if (k == 0) {
    return *this;
  }
  auto multiplier_degree = Natural(k);
  // Проходим по каждому члену многочлена
  for (auto &[degree, _] : coefficients_) {
    // Достаём узел
    auto node = coefficients_.extract(degree);
    // Изменяем ключ
    node.key() += multiplier_degree;
    // Вставляем обратно
    coefficients_.insert(std::move(node));
  }
  return *this;
}

// Умножение многочлена на x^k
// Над модулем работала Майская Вероника, гр. 3384
Polynomial Polynomial::MultiplyByXPower(uint32_t k) const {
  Polynomial result = *this;
  result.MultiplyByXPower(k);
  return result;
}

// Вынесение из многочлена НОК знаменателей коэффициентов и НОД числителей
// Над модулем работал Матвеев Никита, гр. 3383
Rational Polynomial::ToIntegerCoefficients() {
  // Если многочлен пуст, возвращаем множитель 1
  if (coefficients_.empty()) {
    return Rational("1");
  }
  // Инициализация НОД числителей и НОК знаменателей
  auto gcd_numerators = Natural("0");
  auto lcm_denominators = Natural("1");
  // Проходим по коэффициентам многочлена
  for (const auto &[_, coefficient] : coefficients_) {
    // НОД всех числителей коэффициентов
    gcd_numerators = Natural::GreatestCommonDivisor(
        gcd_numerators,
        Natural(Integer::AbsoluteValue(coefficient.GetNumerator())));
    // НОК всех знаменателей коэффициентов
    lcm_denominators = Natural::LeastCommonMultiple(
        lcm_denominators, coefficient.GetDenominator());
  }
  // Формируем множитель как дробь из НОД числителей и НОК знаменателей
  Rational multiplier(
      Integer(gcd_numerators, GetLeadingCoefficient().GetSign()),
      lcm_denominators);
  multiplier.Reduce();

  // Делим коэффициенты на множитель, приводя их к целым числам
  for (auto &[_, coefficient] : coefficients_) {
    coefficient /= multiplier;
  }
  // Возвращаем множитель
  return multiplier;
}

// Наибольший общий делитель многочленов
// Над модулем работал Матвеев Никита, гр. 3383
Polynomial Polynomial::GreatestCommonDivisor(const Polynomial &first,
                                             const Polynomial &second) {
  // Копируем многочлены
  Polynomial a = first;
  Polynomial b = second;
  // Применим алгоритм Евклида
  // Пока один из многочленов не станет равным нулю, продолжаем делить
  while (!b.coefficients_.empty()) {
    // Находим остаток от деления первого на второй
    Polynomial remainder = a % b;
    // Первый становится вторым
    a = b;
    // Второй становится остатком
    b = remainder;
  }
  //
  if (a.GetDegree().IsZero()) a.coefficients_[Natural()] = Rational("1");
  // Возвращается НОД
  return a;
}

// Производная многочлена
// Над модулем работала Кривошеина Дарья, группа 3383
Polynomial Polynomial::Derivative(const Polynomial &polynomial) {
  Polynomial derivative;
  // цикл идет по степеням слагаемых переданного многочлена и их коэффициентам
  for (const auto &[degree, coefficient] : polynomial.coefficients_) {
    // если степень слагаемого до взятия производной равна 0, оно не
    // добавляется, так как обнулится
    if (degree == Natural(0)) continue;
    // коэффициент равен произведению старого коэффициента на степень слагаемого
    Rational derivative_coefficient = coefficient * Rational(Integer(degree));
    // степень понижается на единицу
    derivative.coefficients_[degree - Natural("1")] = derivative_coefficient;
  }
  return derivative;
}

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

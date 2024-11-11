
#include "polynomial.h"

Polynomial Polynomial::operator+(const Polynomial &rhs) const { return {}; }

Polynomial Polynomial::operator-(const Polynomial &rhs) const { return {}; }

Polynomial Polynomial::operator*(const Rational &scalar) const { return {}; }

Polynomial Polynomial::operator*(const Polynomial &rhs) const { return {}; }

Polynomial Polynomial::operator/(const Polynomial &rhs) const { return {}; }

Polynomial Polynomial::operator%(const Polynomial &rhs) const { return {}; }

Polynomial &Polynomial::operator+=(const Polynomial &rhs) { return *this; }

Polynomial &Polynomial::operator-=(const Polynomial &rhs) { return *this; }

Polynomial &Polynomial::operator*=(const Rational &scalar) { return *this; }

Polynomial &Polynomial::operator*=(const Polynomial &rhs) { return *this; }

Polynomial &Polynomial::operator/=(const Polynomial &rhs) { return *this; }

Polynomial &Polynomial::operator%=(const Polynomial &rhs) { return *this; }

Polynomial &Polynomial::MultiplyByXPower(uint32_t k) { return *this; }

// Вынесение из многочлена НОК знаменателей коэффициентов и НОД числителей
// Над модулем работал Матвеев Никита гр 3383
Rational Polynomial::ToIntegerCoefficients() {
  // массив числителей
  std::vector<Integer> numerators;
  // массив числетелей, но в натуральном виде
  std::vector<Natural> nat_numerators;
  // массив знаменателей
  std::vector<Natural> denominators;
  // массив для новых числителей
  std::vector<Integer> new_numerators;
  // массив для новых знаменателей
  std::vector<Natural> new_denominators;
  // считывается из словаря числители и знаменатели
  for (auto& i : this->coefficients_){
    numerators.push_back(i.second.GetNumerator());
    nat_numerators.push_back(Natural(i.second.GetNumerator()));
    denominators.push_back(i.second.GetDenominator());
  }
  // для начала нод равен первому числителю
  Natural nod = nat_numerators[0];
  // для начала нок равен первому знаменателю
  Natural nok = denominators[0];
  // обход всех числителей и знаменателей для нахождения нод, нок
  for (size_t i = 1; i < numerators.size(); ++i) {
    // находится нод между текущим значением и очередным числителем
    nod = Natural::GreatestCommonDivisor(nod, nat_numerators[i]);
    // находится ноr между текущим значением и очередным знаменателем
    nok = Natural::LeastCommonMultiple(nok, denominators[i]);
  }
  nat_numerators.clear();
  // нахождение новых коэффициентов
  for (size_t i = 0; i < numerators.size(); ++i) {
    // добавляем в массив новых числителей: искходный числитель / нод числителей
    new_numerators.push_back(numerators[i] / Integer(nod));
    Natural q = nok / denominators[i];
    // домножение нового числителя на частное от нока и знаменателя
    new_numerators.back() *= Integer(q);
    // если частное равно одному, то и новый знаменатель равен 1
    if (q == Natural(1)) {
      new_denominators.push_back(q);
    } else { // иначе новый знаменатель равен изначальному
      new_denominators.push_back(denominators[i]);
    }
  }
  // рациональное цисло, у которого в числителе нод числителей коэффициентов, а знаменатель нок знаменателей
  Rational result(Integer(nod), nok);
  size_t id = 0;
  // меняем у исходного многочлена коэффициенты, при этом сокращаем если дробь сократимая
  for (auto& i : this->coefficients_){
    i.second = Rational(new_numerators[id], new_denominators[id]).Reduce();
    id++;
  }
  return result.Reduce();
}

// НОД многочленов
// Над модулем работал Матвеев Никита гр. 3383
Polynomial Polynomial::GreatestCommonDivisor(const Polynomial &first, const Polynomial &second) {
    Polynomial dividend; // делимое
    Polynomial divisor; // делитель
    Polynomial remains; // для хранения остатка
    if (first.GetDegree() >= second.GetDegree()) { // если степень первого превосходи или равна второму
        dividend = first; // делимое - первое число, делитель второе
        divisor = second;
    } else { // иначе числа меняются местами
        dividend = second;
        divisor = first;
    }
    remains = dividend % divisor; // первый раз находим остаток от деления первого на второго
    while (!remains.coefficients_.empty()) { // пока отсаток не равен 0 (не пуст равнозначно)
        dividend = divisor; // теперь делимое - бывший делитель
        divisor = remains; // делитель - получившийся остаток
        remains = dividend % divisor; // новый остаток от деления новых элементов
    }
    divisor.ToIntegerCoefficients(); // выносится общий множитель коэффициентов 
    return divisor;
}

Polynomial Polynomial::Derivative(const Polynomial &polynomial) { return {}; }

Polynomial Polynomial::NormalizeRoots(const Polynomial &polynomial) {
  return {};
}

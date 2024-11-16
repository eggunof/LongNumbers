
#ifndef NUMBERS_POLYNOMIAL_H_
#define NUMBERS_POLYNOMIAL_H_

#include <map>
#include <stdexcept>

#include "natural.h"
#include "rational.h"

/**
 * @struct Comparator
 * @brief Компаратор для сортировки коэффициентов полинома по убыванию степени
 */
struct Comparator {
  /**
   * @brief Сравнивает степени двух членов полинома
   * @param first Первая степень
   * @param second Вторая степень
   * @returns true, если первая степень больше второй
   */
  bool operator()(const Natural &first, const Natural &second) const {
    return first > second;
  }
};

/**
 * @class Polynomial
 * @brief Класс для работы с полиномами
 */
class Polynomial {
 protected:
  /** @brief Коэффициенты полинома, отсортированные по степеням */
  std::map<Natural, Rational, Comparator> coefficients_;

 public:
  /**
   * @brief Конструктор по умолчанию, создаёт нулевой полином
   */
  Polynomial() = default;

  /**
   * @brief Конструктор из std::map коэффициентов
   * @param coefficients Коэффициенты полинома (ключ — степень, значение —
   * коэффициент)
   */
  explicit Polynomial(
      const std::map<Natural, Rational, Comparator> &coefficients);

  /**
   * @brief Конструктор монома из степени и коэффициента
   * @param degree Степень члена полинома
   * @param coefficient Коэффициент при степени
   */
  Polynomial(const Natural &degree, const Rational &coefficient);

  /**
   * @brief Конструктор из строки
   * @param string Строковое представление полинома
   */
  explicit Polynomial(const std::string &string);

  /**
   * @brief Конструктор копирования
   * @param other Копируемый полином
   */
  Polynomial(const Polynomial &other) = default;

  /**
   * @brief Оператор присваивания копированием
   * @param other Полином для присваивания
   * @returns Ссылка на текущий полином
   */
  Polynomial &operator=(const Polynomial &other) = default;

  /**
   * @brief Конструктор перемещения
   * @param other Перемещаемый полином
   */
  Polynomial(Polynomial &&other) = default;

  /**
   * @brief Оператор присваивания перемещением
   * @param other Полином для перемещения
   * @returns Ссылка на текущий полином
   */
  Polynomial &operator=(Polynomial &&other) = default;

  /**
   * @brief Получение степени полинома
   * @returns Наибольшая степень полинома
   * @author Кривошеина Дарья, гр. 3383
   */
  [[nodiscard]] Natural GetDegree() const;

  /**
   * @brief Получение старшего коэффициента
   * @returns Коэффициент при старшей степени
   * @author Егунов Даниил, гр. 3383
   */
  [[nodiscard]] Rational GetLeadingCoefficient() const;

  /**
   * @brief Оператор равенства
   * @param rhs Полином для сравнения
   * @returns true, если полиномы равны, иначе false
   */
  bool operator==(const Polynomial &rhs) const;

  /**
   * @brief Оператор неравенства
   * @param rhs Полином для сравнения
   * @returns true, если полиномы не равны, иначе false
   */
  bool operator!=(const Polynomial &rhs) const;

  /**
   * @brief Оператор смены знака полинома
   * @returns Ссылка на изменённый полином
   */
  Polynomial &operator-();

  /**
   * @brief Оператор смены знака полинома
   * @returns Полином с инвертированными коэффициентами
   */
  Polynomial operator-() const;

  /**
   * @brief Оператор сложения полиномов
   * @param rhs Полином для сложения
   * @returns Ссылка на изменённый полином
   * @author Варфоломеева Арина, гр. 3383
   */
  Polynomial &operator+=(const Polynomial &rhs);

  /**
   * @brief Оператор сложения полиномов
   * @param rhs Полином для сложения
   * @returns Результат сложения
   * @author Варфоломеева Арина, гр. 3383
   */
  Polynomial operator+(const Polynomial &rhs) const;

  /**
   * @brief Оператор вычитания полиномов
   * @param rhs Полином для вычитания
   * @returns Ссылка на изменённый полином
   * @author Солдунова Екатерина, гр. 3383
   */
  Polynomial &operator-=(const Polynomial &rhs);

  /**
   * @brief Оператор вычитания полиномов
   * @param rhs Полином для вычитания
   * @returns Результат вычитания
   * @author Солдунова Екатерина, гр. 3383
   */
  Polynomial operator-(const Polynomial &rhs) const;

  /**
   * @brief Умножение полинома на рациональное число
   * @param scalar Множитель
   * @returns Ссылка на изменённый полином
   * @author Кадникова Анна, гр. 3384
   */
  Polynomial &operator*=(const Rational &scalar);

  /**
   * @brief Умножение полинома на рациональное число
   * @param scalar Множитель
   * @returns Результат умножения
   * @author Кадникова Анна, гр. 3384
   */
  Polynomial operator*(const Rational &scalar) const;

  /**
   * @brief Умножение полинома на другой полином
   * @param rhs Полином для умножения
   * @returns Ссылка на изменённый полином
   * @author Дмитриева Дарья, гр. 3383
   */
  Polynomial &operator*=(const Polynomial &rhs);

  /**
   * @brief Умножение полинома на другой полином
   * @param rhs Полином для умножения
   * @returns Результат умножения
   * @author Дмитриева Дарья, гр. 3383
   */
  Polynomial operator*(const Polynomial &rhs) const;

  /**
   * @brief Деление полинома на другой полином
   * @param rhs Делитель
   * @returns Ссылка на изменённый полином
   * @author Солдунова Екатерина, гр. 3383
   */
  Polynomial &operator/=(const Polynomial &rhs);

  /**
   * @brief Деление полинома на другой полином
   * @param rhs Делитель
   * @returns Результат деления
   * @author Солдунова Екатерина, гр. 3383
   */
  Polynomial operator/(const Polynomial &rhs) const;

  /**
   * @brief Остаток от деления полинома
   * @param rhs Делитель
   * @returns Ссылка на изменённый полином
   * @author Дмитриева Дарья, гр. 3383
   */
  Polynomial &operator%=(const Polynomial &rhs);

  /**
   * @brief Остаток от деления полинома
   * @param rhs Делитель
   * @returns Остаток от деления
   * @author Дмитриева Дарья, гр. 3383
   */
  Polynomial operator%(const Polynomial &rhs) const;

  /**
   * @brief Умножение полинома на x^k
   * @param k Степень x
   * @returns Ссылка на изменённый полином
   * @author Майская Вероника, гр. 3384
   */
  Polynomial &MultiplyByXPower(uint32_t k);

  /**
   * @brief Умножение полинома на x^k без изменения исходного полинома
   * @param k Степень x
   * @returns Результат умножения
   * @author Майская Вероника, гр. 3384
   */
  [[nodiscard]] Polynomial MultiplyByXPower(uint32_t k) const;

  /**
   * @brief Приведение коэффициентов полинома к целым числам
   * @returns Вынесенный множитель
   * @author Матвеев Никита, гр. 3383
   */
  Rational ToIntegerCoefficients();

  /**
   * @brief НОД двух полиномов
   * @param first Первый полином
   * @param second Второй полином
   * @returns Наибольший общий делитель
   * @author Матвеев Никита, гр. 3383
   */
  static Polynomial GreatestCommonDivisor(const Polynomial &first,
                                          const Polynomial &second);

  /**
   * @brief Производная полинома
   * @param polynomial Исходный полином
   * @returns Производная полинома
   * @author Кривошеина Дарья, группа 3383
   */
  static Polynomial Derivative(const Polynomial &polynomial);

  /**
   * @brief Нормализация корней полинома
   * @param polynomial Исходный полином
   * @returns Полином с нормализованными корнями
   * @author Кривошеина Дарья, группа 3383
   */
  static Polynomial NormalizeRoots(const Polynomial &polynomial);

  /**
   * @brief Оператор ввода из потока
   * @param is Поток ввода
   * @param polynomial Полином
   * @returns Поток ввода
   */
  friend std::istream &operator>>(std::istream &is, Polynomial &polynomial);

  /**
   * @brief Оператор вывода в поток
   * @param os Поток вывода
   * @param polynomial Полином
   * @returns Поток вывода
   */
  friend std::ostream &operator<<(std::ostream &os,
                                  const Polynomial &polynomial);

  /**
   * @brief Преобразование полинома в строку
   * @returns Строковое представление полинома
   */
  [[nodiscard]] std::string ToString() const;
};

#endif  // NUMBERS_POLYNOMIAL_H_


#include "N.h"

uint8_t COM_NN_D(N a, N b) {
  return 0;
}

bool NZER_N_B(N a) {
  return false;
}

N ADD_1N_N(N a) {
  return N();
}

// сложение натурального числа a и натурального числа b
N ADD_NN_N(N a, N b) {
  if (b.size() > a.size()) { // длина b больше длины a
        for (size_t i = 0; i <= (b.size() - a.size()); i++) { // заполнение 0 разряды, которых нет у a
            a.insert(a.begin(), 0);
        }
    }
    else if (a.size() > b.size()) { // длина a больше длины b
        for (size_t i = 0; i <= (a.size() - b.size()); i++) { // заполнение 0 разряды, которых нет у b
            b.insert(b.begin(), 0);
        }
    }
    Digit surplus = 0; // избыток
    Digit old_a; // для хранения изначальной цифры разряда числа a
    for (int i = a.size() - 1; i >= 0; i--) { // сложение по разрядам (справа налево)
        old_a = a[i];
        a[i] = (a[i] + b[i] + surplus) % 10; // сложение цифр одинакого разряда a, b и избытка; замена текущего разряда a на остаток от деления на 10
        surplus = (old_a + b[i] + surplus) / 10; // сохранение избытка путём деления нацело суммы разрядов a, b и избытка
    }
    if (surplus != 0) {
        a.insert(a.begin(), surplus); // если избыток не равен 0, дописать его в начало
    }
    return a;
}

N SUB_NN_N(N a, N b) {
  return N();
}

N MUL_ND_N(N a, Digit d) {
  return N();
}

N MUL_Nk_N(N a, uint32_t k) {
  return N();
}

N MUL_NN_N(N a, N b) {
  return N();
}

N SUB_NDN_N(N a, N b, Digit d) {
  return N();
}

Digit DIV_NN_Dk(N a, N b, uint32_t k) {
  return 0;
}

N DIV_NN_N(N a, N b) {
  return N();
}

N MOD_NN_N(N a, N b) {
  return N();
}

N GCF_NN_N(N a, N b) {
  return N();
}

N LCM_NN_N(N a, N b) {
  return N();
}

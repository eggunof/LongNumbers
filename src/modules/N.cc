
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

N ADD_NN_N(N a, N b) {
  return N();
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

// Вычисление первой цифры деления большего натурального на меньшее, домноженное на 10^k,где k - номер позиции этой цифры
Digit DIV_NN_Dk(N a, N b) {
    uint32_t k; // это позиция первой значащей цифры частного (считая от старшего разряда)
    N big;
    N small;
    if (COM_NN_D(a, b) == 2) { // a больше b
        big = a;
        small = b;
    }
    else { // a меньше или равно b
        big = b;
        small = a;
    }
    k = big.size() - small.size(); // вычисление номера позиции первой цифры при делении натуральных
    small = MUL_Nk_N(small, k); // умножение меньшего натурального числа на 10^k
    Digit firstDigit = 0;
    while (COM_NN_D(big, small) == 2 || COM_NN_D(big, small) == 0) { // Пока большее натуральное больше или равно меньшему
        big = SUB_NN_N(big, small); // вычитание меньшего из большего
        firstDigit++; // увеличивание первой цифры частного
    }
    return firstDigit; // возвращение первой цифры частного
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

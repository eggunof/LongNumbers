
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

Digit DIV_NN_Dk(N a, N b, uint32_t k) {
  return 0;
}

N DIV_NN_N(N a, N b) {
  return N();
}

N MOD_NN_N(N a, N b) {
  return N();
}

//Функция вычисления НОД двух натуральных чисел
//Над модулем работала Кадникова Анна, гр. 3384
N GCF_NN_N(N a, N b) {
  if(!NZER_N_B(a)){
        return b;
    }else if(!NZER_N_B(b)){
        return a;
  }

  N higher = a;
  N lower = b;

  if (COM_NN_D(a, b) == 1) { 
    // если A < B
    higher = b;
    lower = a;
  }

  // Алгоритм Евклида
    while (NZER_N_B(lower)) {
        // Вычитается меньшее число из большего, пока одно из чисел не станет нулем
        N remainder = SUB_NN_N(higher, lower);

        // Переназначается higher и lower для следующей итерации
        higher = lower;
        lower = remainder;
    }
  // Возвращается НОД
  return higher;
}

N LCM_NN_N(N a, N b) {
  return N();
}

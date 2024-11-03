
#include "N.h"

uint8_t COM_NN_D(N a, N b) {
  // 	Сравнение натуральных чисел: 2 - если первое больше второго, 0, если равно, 1 иначе.
  int n1 = a.size() - 1;
  int n2 = b.size() - 1;

  if (n1 > n2) return 2; // Сравниваем длины чисел, если длина первого больше - возвращаем 2
  if (n1 < n2) return 1; // Если длина второго числа больше - возвращаем 1
  
  // Если длины чисел равны, сравниваем их поразрядно
  for (int i = 0; i <= n1; i++) {
      if (a[i] > b[i]) return 2;
      if (a[i] < b[i]) return 1;
  }
  
  return 0; // Возвращаем 0, если числа равны
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

N GCF_NN_N(N a, N b) {
  return N();
}

N LCM_NN_N(N a, N b) {
  return N();
}

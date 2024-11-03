
#include "N.h"

uint8_t COM_NN_D(const N &a, const N &b) {
  return 0;
}

bool NZER_N_B(const N &a) {
  return false;
}

// добавление 1 к натуральному числу
N ADD_1N_N(const N &a) {
  N A = a;
  int n = A.size()-1;
	A[n] += 1;
	int i = n;
	while ((A[i] == 10)&&(i>0)){ // если единица прибавляется к 9, то обнуляем разряд и добавляем 1 в следующий
		A[i] = 0;
		i -= 1;
		A[i] += 1;
	}
	if ((i == 0)&&(A[0] == 10)){
		A[0] = 0;
		auto iter = A.cbegin();
		A.emplace(iter, 1); // если при прибавлении единмицы увеличилось число разрядов, вставляем в начало числа единицу
		n += 1;
	}
  return A;
}

N ADD_NN_N(const N &a, const N &b) {
  return N();
}

N SUB_NN_N(const N &a, const N &b) {
  return N();
}

N MUL_ND_N(const N &a, const Digit &d) {
  return N();
}

N MUL_Nk_N(const N &a, const uint32_t &k) {
  return N();
}

N MUL_NN_N(const N &a, const N &b) {
  return N();
}

N SUB_NDN_N(const N &a, const N &b, const Digit &d) {
  return N();
}

Digit DIV_NN_Dk(const N &a, const N &b, const uint32_t &k) {
  return 0;
}

N DIV_NN_N(const N &a, const N &b) {
  return N();
}

N MOD_NN_N(const N &a, const N &b) {
  return N();
}

N GCF_NN_N(const N &a, const N &b) {
  return N();
}

N LCM_NN_N(const N &a, const N &b) {
  return N();
}

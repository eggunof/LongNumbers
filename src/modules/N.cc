
#include "N.h"

uint8_t COM_NN_D(N a, N b) {
  return 0;
}

//Сравнение Натурального числа с нулём
//Над модулем работала Кадникова Анна, гр. 3384
bool NZER_N_B(N a) {
  //Признак нуля: длина числа 1 и в старшем разряде записан 0
  return ((a.size()==1) && (a[0]==0));
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

N GCF_NN_N(N a, N b){
  return N();
}

N LCM_NN_N(N a, N b) {
  return N();
}

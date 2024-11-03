
#ifndef LONGNUMBERS_SRC_MODULES_N_H_
#define LONGNUMBERS_SRC_MODULES_N_H_

#include <cstdint>
#include <vector>

typedef uint8_t Digit;
typedef std::vector<Digit> N;

uint8_t COM_NN_D(const N &a, const N &b);

bool NZER_N_B(const N &a);

N ADD_1N_N(const N &a);

N ADD_NN_N(const N &a, const N &b);

N SUB_NN_N(const N &a, const N &b);

N MUL_ND_N(const N &a, const Digit &d);

N MUL_Nk_N(const N &a, const uint32_t &k);

N MUL_NN_N(const N &a, const N &b);

N SUB_NDN_N(const N &a, const N &b, const Digit &d);

Digit DIV_NN_Dk(const N &a, const N &b, const uint32_t &k);

N DIV_NN_N(const N &a, const N &b);

N MOD_NN_N(const N &a, const N &b);

N GCF_NN_N(const N &a, const N &b);

N LCM_NN_N(const N &a, const N &b);

#endif //LONGNUMBERS_SRC_MODULES_N_H_

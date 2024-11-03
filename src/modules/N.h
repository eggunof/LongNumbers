
#ifndef LONGNUMBERS_SRC_MODULES_N_H_
#define LONGNUMBERS_SRC_MODULES_N_H_

#include <cstdint>
#include <vector>

typedef uint8_t Digit;
typedef std::vector<Digit> N;

uint8_t COM_NN_D(N a, N b);

bool NZER_N_B(N a);

N ADD_1N_N(N a);

N ADD_NN_N(N a, N b);

N SUB_NN_N(N a, N b);

N MUL_ND_N(N a, Digit d);

N MUL_Nk_N(N a, uint32_t k);

N MUL_NN_N(N a, N b);

N SUB_NDN_N(N a, N b, Digit d);

Digit DIV_NN_Dk(N a, N b, uint32_t k);

N DIV_NN_N(N a, N b);

N MOD_NN_N(N a, N b);

N GCF_NN_N(N a, N b);

N LCM_NN_N(N a, N b);

#endif //LONGNUMBERS_SRC_MODULES_N_H_

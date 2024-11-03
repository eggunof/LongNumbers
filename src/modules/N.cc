
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

//Неполное частное
N DIV_NN_N(N a, N b) {
    // Если A < B, то неполное частное равно 0
    if (COM_NN_D(a, b) == 1) {
        return N({0});
    }

    size_t counter = 0;
    // Вычитаем из числа A число B пока у нас А >= B
    while (COM_NN_D(a, b) != 1) {
        a = SUB_NN_N(a, b); // Сохраняем результат вычитания в 'a'
        counter++;
    }

    // Преобразуем counter в вектор
    std::vector<Digit> result;
    while (counter > 0) {
        result.push_back(counter % 10); // Получаем последнюю цифру
        counter /= 10; // Удаляем последнюю цифру
    }

    // Переворачиваем вектор для правильного порядка цифр
    size_t left = 0;
    size_t right = result.size() - 1;
    while (left < right) {
        std::swap(result[left], result[right]);
        left++;
        right--;
    }

    return result;
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

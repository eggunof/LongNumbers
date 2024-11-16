#include <iostream>
#include <string>

#include "menu.h"
#include "operations.h"

int main() {
  while (true) {
    PrintModulesMenu();
    int main_choice;
    int module_choice;
    std::cin >> main_choice;
    try {
      switch (main_choice) {
        case 1:
          PrintNaturalMenu();
          std::cin >> module_choice;
          if (module_choice == 15) break;
          PerformNaturalOperation(module_choice);
          break;
        case 2:
          PrintIntegerMenu();
          std::cin >> module_choice;
          if (module_choice == 11) break;
          PerformIntegerOperation(module_choice);
          break;
        case 3:
          PrintRationalMenu();
          std::cin >> module_choice;
          if (module_choice == 11) break;
          PerformRationalOperation(module_choice);
          break;
        case 4:
          PrintPolynomialMenu();
          std::cin >> module_choice;
          if (module_choice == 14) break;
          PerformPolynomialOperation(module_choice);
          break;
        case 5:
          std::cout << "Выход" << std ::endl;
          break;
        default:
          std::cout << "Неверный выбор" << std::endl;
      }
    } catch (std::exception& e) {
      std::cout << "Ошибка: " << e.what() << std::endl;
    }

    if (main_choice == 5) break;
  }
  return 0;
}

#include <iostream>

int main() {
  float numbers[15];
  std::cout << "Enter numbers:" << std::endl;
  for (int i = 0; i < 15; i++) {
    std::cin >> numbers[i];
  }

  std::cout << "Output: " << std::endl;

  for (int i = 0; i < 15; i++) {
    for (int j = 0; j < 15; j++) {
      if (numbers[i] < numbers[j]) {
        float buff = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = buff;
      }

      if (i == 14) std::cout << numbers[j] << " ";
    }
  }
}
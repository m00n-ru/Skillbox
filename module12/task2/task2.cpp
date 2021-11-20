#include <iostream>

int main() {
  int numbers[15] = {114, 111, 106, 107, 108, 105, 115, 108,
                     110, 109, 112, 113, 116, 117, 118};
  int repitNum = 0;
  for (int i = 0; i < 15; i++) {
    for (int j = 0; j < 15; j++) {
      if (i == j) {
        continue;
      } else {
        if (numbers[i] == numbers[j]) {
          repitNum = numbers[j];
          break;
        }
      }
    }
  }
  std::cout << "Repeating number: " << repitNum;
}

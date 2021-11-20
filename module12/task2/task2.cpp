#include <iostream>

int main() {
  int numbers[15] = {114, 111, 106, 107, 108, 105, 115, 108,
                     110, 109, 112, 113, 116, 117, 118};
  int sum = 0;
  int min = numbers[0];
  for (int i = 0; i < 15; i++) {
    sum += numbers[i] - i;
    if (numbers[i] <= min) min = numbers[i];
  }
  int repitNum = sum + 14 - 14 * min;

  std::cout << "Repeating number: " << repitNum;
}

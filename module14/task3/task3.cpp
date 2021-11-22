#include <iostream>

int main() {
  int snake[5][5];
  for (int i = 0; i < 25; i++) {
    int a = (i / 5) % 2;
    snake[i / 5][i % 5] = (i + (9 + 5 * (i / 5 - 1)) * a) - (i + i % 5) * a;
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      std::cout << snake[i][j] << "\t";
    }
    std::cout << std::endl;
  }
}
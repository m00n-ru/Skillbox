#include <iostream>

void input(float a[][4]) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      std::cin >> a[i][j];
    }
  }
}

void output(float a[][4]) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      std::cout << a[i][j];
    }
    std::cout << std::endl;
  }
}

int main() {
  float a[4][4];
	std::cout << "Input: ";
  input(a);

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (i != j) a[i][j] = 0;
    }
  }

  output(a);
}
#include <iostream>

void input(int a[][4]) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      std::cin >> a[i][j];
    }
  }
}

int main() {
  int a[4][4];
  int b[4][4];

  std::cout << "Input 1: ";
  input(a);
  std::cout << "Input 2: ";
  input(b);

  bool equal = true;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (a[i][j] != b[i][j]) {
        equal = false;
        break;
      }
    }
  }
  if (equal) {
    std::cout << "equal";
  } else {
    std::cout << "unequal";
  }
}
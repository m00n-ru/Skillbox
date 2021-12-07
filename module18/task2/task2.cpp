#include <iostream>

// rabbit +1 +2 +3 -> n

int numMethod(int n) {
  if (n == 0) {
    return 1;
  } else if (n == 1) {
    return numMethod(n - 1);
  } else if (n == 2) {
    return numMethod(n - 1) + numMethod(n - 2);
  } else {
    return numMethod(n - 1) + numMethod(n - 2) + numMethod(n - 3);
  }
}

int main() {
  int n;
  std::cout << "Enter n= ";
  std::cin >> n;
  std::cout << numMethod(n);
}
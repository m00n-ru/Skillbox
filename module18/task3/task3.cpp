#include <iostream>

// rabbit +1 +2 +3 -> n

int numMethod(int n, int k = 3) {
  if (n == 0) return 1;
  int step = 0;
  for (int i = 1; i <= (n > k ? k : n); i++) {
    step += numMethod(n - i, k);
  }
  return step;
}

int main() {
  int n, k;
  std::cout << "Enter n= ";
  std::cin >> n;
  std::cout << "Enter k= ";
  std::cin >> k;
  if (k > 0) {
    std::cout << numMethod(n, k);
  } else {
    std::cout << numMethod(n);
  }
}
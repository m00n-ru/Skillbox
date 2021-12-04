#include <iostream>

void revers(int* a) {
  for (int i = 0; i < 5; i++) {
    int buff;
    buff = *(a + i);
    *(a + i) = *(a + 9 - i);
    *(a + 9 - i) = buff;
  }
}

int main() {
  int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  revers(a);
  for (int i = 0; i < 10; i++) {
    std::cout << *(a + i);
  }
}

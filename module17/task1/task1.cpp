#include <iostream>

void swap(int* a, int* b) {
  int buff;
  buff = *a;
  *a = *b;
  *b = buff;
}

int main() {
  int a = 10;
  int b = 20;
  swap(&a, &b);
  std::cout << a << " " << b;
}

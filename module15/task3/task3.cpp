#include <iostream>
#include <vector>

int main() {
  std::vector<int> v;
  int a;
  int count = 0;
  while (true) {
    std::cin >> a;
    if (a == -1) {
      if (count < 5) {
        std::cout << "Error, need 5 elements" << std::endl;
      } else {
        std::cout << "Answ.: " << v[4];
      }
    } else if (a == -2) {
      break;
    } else {
      v.push_back(a);
      for (int i = v.size() - 1; i >= 1; i--) {
        if (v[i] < v[i - 1]) {
          int buff = v[i - 1];
          v[i - 1] = v[i];
          v[i] = buff;
        }
      }
      if (v.size() > 5) v.resize(5);
    }
    ++count;
  }
}

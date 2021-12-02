#include <iostream>
#include <vector>

int main() {
  int sum = 9;
  std::vector<int> v{5, 2, 7, 11, 15};
  bool check = true;

  for (int i = 0; i < v.size() - 1 && check; i++) {
    for (int j = 1; j < v.size() && check; j++) {
      if (v[i] + v[j] == sum) {
        std::cout << i << " " << j;
        check = false;
      }
    }
  }
}
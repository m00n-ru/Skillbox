#include <iostream>
#include <vector>

int main() {
  std::vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  int sum = v[0];
  int buff = sum;
  int i = 0;
  int j = 0;
  int startPos = -1;
  for (int k = 0; k < v.size(); k++) {
    sum += v[k];
    if (sum > buff) {
      j = k;
      i = startPos + 1;
      buff = sum;
    }
    if (sum < 0) {
      startPos = k;
      sum = 0;
    }
  }
  std::cout << i << " " << j;
}

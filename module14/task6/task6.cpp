#include <iostream>
#include <vector>

void input(int a[][4]) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      std::cin >> a[i][j];
    }
  }
}

int main() {
  std::vector<int> v(4);
  std::vector<int> r(4);
  int m[4][4];

  std::cout << "Input array" << std::endl;
  input(m);

  std::cout << "Input vector" << std::endl;
  for (int i = 0; i < 4; i++) {
    std::cin >> v[i];
  }

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      r[i] += m[i][j] * v[j];
    }
  }
	
	std::cout << "Sum vector:" << std::endl;
  for (int i = 0; i < 4; i++) {
    std::cout << r[i] << " ";
  }
}
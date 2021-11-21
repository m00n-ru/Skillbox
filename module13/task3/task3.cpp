#include <iostream>
#include <vector>

int main() {
  std::vector<int> base;
	int baseSize = 20;
  int num = 0;
  std::cout << "Fill base" << std::endl;

  while (true) {
    std::cin >> num;
    if (num == -1) break;
    if (base.size() < baseSize) {
      base.push_back(num);
    } else {
      base.erase(base.begin());
      base.push_back(num);
    }
  }

  if (base.empty()) {
    std::cout << "Empty base" << std::endl;
  } else {
    for (int i = 0; i < base.size(); i++) {
      std::cout << base[i] << ' ';
    }
  }
}
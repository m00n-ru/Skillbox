#include <iostream>
#include <vector>

int main() {
  std::vector<int> base(3);
  int num = 0;
  std::cout << "Fill base" << std::endl;
  int buff = 0;

  while (true) {
    std::cin >> num;
    if (num == -1) break;

    base[buff++] = num;
    if (buff == base.size()) buff = 0;
  }

  for (int i = 0; i < base.size(); i++) {
    if (buff + i == base.size()) buff = buff - base.size();
    std::cout << base[buff + i] << ' ';
  }
}
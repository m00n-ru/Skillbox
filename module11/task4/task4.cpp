#include <iostream>

bool correctCh(char ch, int i) {
  if ((i == 0 && ch == '-') || ch == '.' || (ch >= '0' && ch <= '9')) {
    return true;
  } else {
    return false;
  }
}

bool correctNum(std::string num) {
  int point = 0;
  for (int i = 0; i < num.length(); i++) {
    if (num[i] == '.') point += 1;
    if (!(correctCh(num[i], i)) || point == 2) return false;
    if (num.length() == 2 && num[0] == '-' && num[1] == '.') return false;
  }
  return true;
}

int compareNum(std::string num1, std::string num2) {
  if (correctNum(num1) && correctNum(num2)) {
    if (num1[0] == '-' && num2[0] == '-') {
      return -num1.compare(num2);
    } else {
      return num1.compare(num2);
    }
  }
}

int main() {
  std::string numbers1;
  std::string numbers2;

  std::cout << "Enter two numbers to compare: ";
  std::cin >> numbers1;
  std::cin >> numbers2;

  std::cout << (compareNum(numbers1, numbers2) > 0   ? "MORE"
                : compareNum(numbers1, numbers2) < 0 ? "LESS"
                                                     : "EQUAL");
  std::cout << std::endl;
}

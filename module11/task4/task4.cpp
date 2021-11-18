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

int compareFunc(std::string num1, std::string num2, int parI, int parJ) {
  int i;
  int j;
  bool point = false;
  for (i = parI; i < num1.length() && num1[i] == '0' && num1.length() != 1;
       i++) {
  }
  for (j = parJ; j < num2.length() && num2[j] == '0' && num2.length() != 1;
       j++) {
  }
  bool endStr1 = false;
  bool endStr2 = false;
  int length = std::max(num1.length() - i, num2.length() - j);
  for (int k = 0; k < length; k++) {
    if (num1[i] == '.') point = true;
    if (num2[j] == '.') point = true;
    bool check = k == 0 && point && (num1[i] == '0' || num2[j] == '0');
    if (!endStr1 && !endStr2 && !check) {
      if (num1[i] > num2[j]) {
        return 1;
      } else if (num1[i] < num2[j]) {
        return -1;
      }
    } else if (endStr1 && !endStr2) {
      if (!point) {
        if (num2[j] == '.') {
          point = true;
        } else {
          return -1;
        }
      } else {
        if (num2[j] != '0') return -1;
      }
    } else if (!endStr1 && endStr2) {
      if (!point) {
        if (num1[i] == '.') {
          point = true;
        } else {
          return 1;
        }
      } else {
        if (num1[i] != '0') return 1;
      }
    }
    (i < num1.length() - 1) ? i++ : endStr1 = true;
    (j < num2.length() - 1) ? j++ : endStr2 = true;
  }
  return 0;
}

int compareNum(std::string num1, std::string num2) {
  if (correctNum(num1) && correctNum(num2)) {
    if (num1[0] != '-' && num2[0] == '-') {
      return compareFunc(num1, num2, 0, 1);
    } else if (num1[0] == '-' && num2[0] != '-') {
      return compareFunc(num1, num2, 1, 0);
    } else if (num1[0] != '-' && num2[0] != '-') {
      return compareFunc(num1, num2, 0, 0);
    } else {
      return -compareFunc(num1, num2, 1, 1);
    }
  } else {
    return 2;
  }
}

int main() {
  while (true) {
    std::string numbers1;
    std::string numbers2;

    std::cout << "Enter two numbers to compare:\n";
    std::cin >> numbers1;
    std::cin >> numbers2;
    int compare = compareNum(numbers1, numbers2);
    std::cout << (compare == 1    ? "MORE"
                  : compare == -1 ? "LESS"
                  : compare == 2  ? "ERROR"
                                  : "EQUAL");
    std::cout << std::endl;
  }
}

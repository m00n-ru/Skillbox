#include <iostream>
#include <string>

bool checkNum(std::string str) {
  for (char i : str) {
    if (!isdigit(i)) return false;
  }
  return true;
}

std::string enterStr() {
  std::string str;
  do {
    std::cin >> str;
    if (!checkNum(str)) {
      std::cout << "Error, only numeric characters!" << std::endl;
      std::cout << "Repeat: ";
    }
  } while (!checkNum(str));
  return str;
}

int main() {
  std::string strFull;

  std::cout << "Enter integer part: ";
  strFull += enterStr() + ".";
  std::cout << "Enter fractional part: ";
  strFull += enterStr();
  std::cout << std::stod(strFull);
}

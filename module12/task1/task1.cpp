#include <iostream>

int main() {
  int apartNum;
  std::string name[10];
  std::cout << "Enter 10 names of tenants: " << std::endl;
  for (int i = 0; i < 10; i++) {
    std ::cin >> name[i];
  }
  std::cout << "Enter apartment number;" << std ::endl;
  for (int i = 0; i < 3; i++) {
    std::cin >> apartNum;
    if (apartNum < 1 || apartNum > 10) {
      std::cout << "ERROR! Incorrect apartment number" << std::endl;
    } else {
      std::cout << name[apartNum - 1] << " lives in aprtment " << apartNum
                << std::endl;
    }
  }
}
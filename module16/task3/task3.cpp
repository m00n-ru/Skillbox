#include <iostream>
#include <sstream>

int main() {
  std::string str;
  std::cout << "Enter the expression: ";
  std::cin >> str;

  std::stringstream expr{str};

  double a;
  double b;
  char c;

  expr >> a >> c >> b;

  if (c == '+') {
    std::cout << a << "+" << b << "= " << a + b;
  } else if (c == '-') {
    std::cout << a << "-" << b << "= " << a - b;
  } else if (c == '*') {
    std::cout << a << "*" << b << "= " << a * b;
  } else if (c == '/') {
    std::cout << a << "/" << b << "= " << a / b;
  } else {
    std::cout << "Error!";
  }
}

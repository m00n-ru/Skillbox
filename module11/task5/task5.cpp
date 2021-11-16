#include <iostream>

bool correctStr(std::string st) {
  if (st.length() != 3) return false;
  for (int i = 0; i < st.length(); i++) {
    if (st[i] != 'X' && st[i] != 'O' && st[i] != '.') return false;
  }
  return true;
}

void checkWin(std::string st) {}

int main() {
  while (true) {
    std::string st1;
    std::string st2;
    std::string st3;
		
    std::cout << "Enter the playing field:" << std::endl;
    std::cin >> st1 >> st2 >> st3;
    if (correctStr(st1) && correctStr(st2) && correctStr(st3)) {
      std::string st = st1 + st2 + st3;
      std::cout << st << std::endl;
    } else {
      std::cout << "Incorrect" << std::endl;
    }
  }
}

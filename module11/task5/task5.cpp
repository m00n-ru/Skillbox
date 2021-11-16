#include <iostream>

bool correctStr(std::string st) {
  if (st.length() != 3) return false;
  for (int i = 0; i < st.length(); i++) {
    if (st[i] != 'X' && st[i] != 'O' && st[i] != '.') return false;
  }
  return true;
}

std::string checkWin(std::string st1, std::string st2, std::string st3) {
  if (correctStr(st1) && correctStr(st2) && correctStr(st3)) {
    int win = 0;
    int numO = 0;
    int numX = 0;
    char winChar = '.';
    std::string st = st1 + st2 + st3;
    for (int i = 0; i < st.length(); i++) {
      if (st[i] == '.') st[i] = '0' + 1;
      if (st[i] == 'O') numO += 1;
      if (st[i] == 'X') numX += 1;
    }

    if (numO <= numX && numX - numO < 2) {
      if (st[0] == st[1] && st[0] == st[2]) {
        win += 1;
        winChar = st[0];
      } else if (st[3] == st[4] && st[3] == st[5]) {
        win += 1;
        winChar = st[3];
      } else if (st[6] == st[7] && st[6] == st[8] && win < 2) {
        win += 1;
        winChar = st[6];
      } else if (st[0] == st[3] && st[0] == st[6] && win < 2) {
				win += 1;
				winChar = st[0];
			} else if (st[1] == st[4] && st[1] == st[7] && win < 2) {
				win += 1;
				winChar = st[1];
			} else if (st[2] == st[5] && st[2] == st[8] && win < 2) {
				win += 1;
				winChar = st[2];
			} else if (st[0] == st[4] && st[0] == st[8] && win < 2) {
				win += 1;
				winChar = st[0];
			}else if (st[2] == st[4] && st[2] == st[6] && win < 2) {
				win += 1;
				winChar = st[2];
			}
      if (win == 0) {
        return "Nobody";
      } else if (winChar == 'O' && numO == numX) {
        return "Vanya";
      } else if (winChar == 'X' && numX > numO) {
        return "Petya";
      } else {
        return "Incorrect";
      }
    } else {
      return "Incorrect";
    }
  } else {
    return "Incorrect";
  }
}

int main() {
  while (true) {
    std::string st1;
    std::string st2;
    std::string st3;

    std::cout << "Enter the playing field:" << std::endl;
    std::cin >> st1 >> st2 >> st3;
    std::cout << checkWin(st1, st2, st3) << std::endl;
  }
}

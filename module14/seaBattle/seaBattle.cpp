#include <iostream>
#include <vector>

// + рисование 2 полей
void drowField(bool field1[][10], bool field2[][10]) {
  char x = 'X';
  std::cout << std::endl;
  std::cout << "       Player 1                Player 2" << std::endl;
  std::cout << "  0 1 2 3 4 5 6 7 8 9     0 1 2 3 4 5 6 7 8 9" << std::endl;
  for (int i = 0; i < 10; i++) {
    std::cout << i;
    for (int j = 0; j < 10; j++) {
      x = field1[i][j] ? 'O' : '.';
      std::cout << " " << x;
    }
    std::cout << "   " << i;
    for (int j = 0; j < 10; j++) {
      x = field2[i][j] ? 'O' : '.';
      std::cout << " " << x;
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

// + проверка кординат на диапазон
// + проверка свободности ячейки
// + проверка кординат в соответ. размерам коробля
bool checkNum(bool field[][10], int x1, int y1, int x2, int y2, int c) {
  if (x1 >= 0 && x1 <= 9 && y1 >= 0 && y1 <= 9 && x2 >= 0 && x2 <= 9 &&
      y2 >= 0 && y2 <= 9) {
    for (int i = 0; i < c; i++) {
      if (c == 1) {
        return field[y1][x1] ? false : true;
      } else if (x1 == x2 && c != 1) {
        if (field[std::min(y1, y2) + i][x1] == false &&
            std::min(y1, y2) + c - 1 == std::max(y1, y2)) {
          return true;
        } else {
          return false;
        }
      } else if (y1 == y2 && c != 1) {
        if (field[y1][std::min(x1, x2) + i] == false &&
            std::min(x1, x2) + c - 1 == std::max(x1, x2)) {
          return true;
        } else {
          return false;
        }
      } else {
        return false;
      }
    }
  }
  return false;
}

// + инициализация поля
void initField(bool field[][10]) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      field[i][j] = false;
    }
  }
}

// + ввод кораблей для поля
void inputField(bool field[][10]) {
  int x1, y1, x2, y2;
  std::cout << "Enter cordinate (x y) 1-cell ship" << std::endl;
  for (int i = 0; i < 4; i++) {
    std::cout << i + 1 << "): ";
    std::cin >> x1 >> y1;
    if (checkNum(field, x1, y1, 0, 0, 1)) {
      field[y1][x1] = true;
    } else {
      std::cout << "Error, repit input" << std::endl;
      --i;
    }
  }

  std::cout << "Enter cordinate (x1 y1 x2 y2) 2-cell ship" << std::endl;
  for (int i = 0; i < 3; i++) {
    std::cout << i + 1 << "): ";
    std::cin >> x1 >> y1 >> x2 >> y2;
    if (checkNum(field, x1, y1, x2, y2, 2)) {
      field[y1][x1] = true;
      field[y2][x2] = true;
    } else {
      std::cout << "Error, repit input" << std::endl;
      --i;
    }
  }

  std::cout << "Enter cordinate (x1 y1 x2 y2) 3-cell ship" << std::endl;
  for (int i = 0; i < 2; i++) {
    std::cout << i + 1 << "): ";
    std::cin >> x1 >> y1 >> x2 >> y2;
    if (checkNum(field, x1, y1, x2, y2, 3)) {
      field[y1][x1] = true;
      field[y2][x2] = true;
      x1 == x2 ? field[std::max(y1, y2) - 1][x1] = true
               : field[y1][std::max(x1, x2) - 1] = true;
    } else {
      std::cout << "Error, repit input" << std::endl;
      --i;
    }
  }

  std::cout << "Enter cordinate (x1 y1 x2 y2) 4-cell ship" << std::endl;
  for (int i = 0; i < 1; i++) {
    std::cout << i + 1 << "): ";
    std::cin >> x1 >> y1 >> x2 >> y2;
    if (checkNum(field, x1, y1, x2, y2, 4)) {
      field[y1][x1] = true;
      field[y2][x2] = true;
      x1 == x2 ? field[std::max(y1, y2) - 1][x1] = true
               : field[y1][std::max(x1, x2) - 1] = true;
      x1 == x2 ? field[std::max(y1, y2) - 2][x1] = true
               : field[y1][std::max(x1, x2) - 2] = true;
    } else {
      std::cout << "Error, repit input" << std::endl;
      --i;
    }
  }
}

// - обработка хода
// - подсечет оставшихся
//void strike() {}
//
// - победитель
//bool win() {}

int main() {
  // 4-1 3-2 2-3 1-4

  bool field1[10][10];
  bool field2[10][10];
  //int pl = 1, x1, y1;

  initField(field1);
  initField(field2);

  std::cout << "Enter possition Player 1:" << std::endl;
  inputField(field1);
  drowField(field1, field2);
  std::cout << "Enter possition Player 2:" << std::endl;
  inputField(field2);
  drowField(field1, field2);

  //	while(win()){
  //		std::cout << "Player " << pl << " turn." << std::endl;
  //		std::cin >> x1 >> y1;
  //		strike();
  //		pl = pl == 1 ? 2 : 1;
  //	}
}

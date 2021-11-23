#include <iostream>
#include <vector>

void init(bool a[][12]) {
  for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 12; j++) {
      a[i][j] = true;
    }
  }
}

int output(bool a[][12], int count) {
  for (int i = 0; i < 12; i++) {
    for (int j = 0; j < 12; j++) {
      if (a[i][j]) {
        std::cout << 'o' << ' ';
      } else {
        std::cout << 'X' << ' ';
        --count;
      }
    }
    std::cout << std::endl;
  }
  std::cout << count << " bubbles left" << std::endl;
  return count;
}

void liquid(bool a[][12], int x1, int y1, int x2, int y2) {
  if (x1 > x2) {
    int xBuff = x2;
    x2 = x1;
    x1 = xBuff;
  }
  if (y1 > y2) {
    int yBuff = y2;
    y2 = y1;
    y1 = yBuff;
  }
  for (int i = y1; i < y2 + 1; i++) {
    for (int j = x1; j < x2 + 1; j++) {
      a[i][j] = false;
      std::cout << "Pop! ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

bool check(int x1, int x2, int y1, int y2) {
  return (x1 < 0 || x1 > 11 || x2 < 0 || x2 > 11 || y1 < 0 || y1 > 11 ||
          y2 < 0 || y2 > 11);
}

int main() {
  bool m[12][12];
  int x1, y1, x2, y2;
  int count = 144;

  init(m);
  output(m, count);

  while (count != 0) {
    std::cout << std::endl << "Liquidation zone (x1 y1 - x2 y2): ";
    std::cin >> x1 >> y1 >> x2 >> y2;
    if (check(x1, x2, y1, y2)) {
      std::cout << "Error. Repit input" << std::endl;
    } else {
      liquid(m, x1, y1, x2, y2);
      count = output(m, count);
    }
    std::cout << "The bubbles are over" << std::endl;
  }
}
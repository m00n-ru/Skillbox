#include <iostream>

int main() {
  int mc[5][5][10];
  int h;
  std::cout << "Input block height;" << std::endl;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      std::cout << i << " " << j << ":";
      std::cin >> h;
      if (h >= 0 && h < 10) {
        for (int k = 0; k < 10; k++) {
          mc[i][j][k] = (k <= h && h != 0) ? 1 : 0;
        }
      } else {
        std::cout << "Repit input" << std::endl;
        --j;
      }
    }
  }

  std::cout << std::endl << "Your world" << std::endl;
  for (int k = 9; k >= 0; k--) {
    std::cout << k << " level:" << std::endl;
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        std::cout << mc[i][j][k] << ' ';
      }
      std::cout << std ::endl;
    }
    std::cout << std ::endl;
  }
}

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::ifstream file;
  std::string pathF;

  do {
    std::cout << "File path: ";
    std::cin >> pathF;
    file.open(pathF, std::ios::binary);
    if (!file.is_open()) {
      std::cout << "Error file path!" << std::endl;
    }
  } while (!file.is_open());

  char strF[4];
  file.read(strF, 4);

  if (strF[0] == -119 && strF[1] == 'P' && strF[2] == 'N' && strF[3] == 'G') {
    if (pathF.substr(pathF.size() - 4) != ".png") {
      std::cout << "Incorrect file extension" << std::endl;
    }
    std::cout << "File has PNG format";
  } else {
    std::cout << "File of UNKNOWN format";
  }
  file.close();
}
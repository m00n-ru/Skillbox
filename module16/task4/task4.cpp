#include <iostream>
#include <sstream>

bool checkError(std::string comb) {
  for (int i = 1; i < comb.length(); i++) {
    if (comb[i] < '1' || comb[i] > '7') {
      std::cout << "Error, incorrect input!" << std::endl;
      return true;
    }
  }
  return false;
}

std::string transNote(std::string comb) {
  std::string str;
  enum piano { d = 1, r, m, f, so, l, si };
  for (int i = 0; i < comb.length(); i++) {
    if (comb[i] - '0' == d) {
      str += "DO ";
    } else if (comb[i] - '0' == r) {
      str += "RE ";
    } else if (comb[i] - '0' == m) {
			str += "ME ";
		} else if (comb[i] - '0' == f) {
			str += "FA ";
		} else if (comb[i] - '0' == so) {
			str += "SOL ";
		} else if (comb[i] - '0' == l) {
			str += "LA ";
		} else if (comb[i] - '0' == si) {
			str += "SI ";
		}
  }
	return str;
}

int main() {
  std::string comb;
  std::stringstream music;

  for (int i = 0; i < 12; i++) {
    std::cout << i + 1 << ". Enter combination: ";
    std::cin >> comb;
    if (checkError(comb)) continue;
    music << transNote(comb) << " " << std::endl;
  }

  std::cout << "Your music" << std::endl;
	std::cout << music.str();
}
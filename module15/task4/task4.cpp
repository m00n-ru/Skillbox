#include <iostream>
#include <vector>

int main() {
  std::vector<int> v = {1, 2, 4};
  int iE = 0;
  int iS = 0;

  for (int i = 0; i < v.size(); i++) {
    if (v[i] >= 0) {
      iE = i;
      iS = i - 1;
      if (iS < 0) iS = v.size() - 1;
      break;
    }
  }

  for (int i = 0; i < v.size(); i++) {
    if (abs(v[iE]) <= abs(v[iS])) {
      std::cout << v[iE] << " ";
      ++iE;
      if (iE == v.size()) iE = 0;
    } else {
      std::cout << v[iS] << " ";
      --iS;
      if (iS < 0) iS = v.size() - 1;
    }
  }
}
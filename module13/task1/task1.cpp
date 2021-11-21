#include <iostream>
#include <vector>

int main() {
  while (true) {
    std::vector<int> vec;
    int n = 0;
    std::cout << "Enter size: ";
    std::cin >> n;
    if (n < 1) {
      std::cout << "ERROR size" << std::endl;
    } else {
      std::cout << "Fill in vector" << std::endl;
      for (int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        vec.push_back(num);
      }

      std::cout << "Which number should be deleted: ";
      std::cin >> n;
      int c = 0;
      for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == n) {
          ++c;
        } else {
          vec[i - c] = vec[i];
        }
      }
      vec.resize(vec.size() - c);

      if (vec.size()) {
        for (int i = 0; i < vec.size(); i++) {
          std::cout << vec[i] << " ";
        }
        std::cout << std ::endl;
      } else {
        std::cout << "Empty, no numbers." << std ::endl;
      }
    }
  }
}
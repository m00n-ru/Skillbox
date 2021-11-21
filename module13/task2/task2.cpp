#include <iostream>
#include <vector>

int main() {
  std::vector<float> price = {2.5, 4.25, 3.0, 10.0};
  std::vector<int> buy = {1, 1, 0, 3};
  float sumBuy = 0;
  bool error = false;
  for (int i = 0; i < buy.size(); i++) {
    if (buy[i] >= 0 || buy[i] < price.size()) {
      if (price[buy[i]] > 0) {
        sumBuy += price[buy[i]];
      } else {
        std::cout << "ERROR. In position " << buy[i] << " price vector"
                  << std::endl;
        error = true;
      }
    } else {
      std::cout << "ERROR. In position " << i << " buy vector" << std::endl;
      error = true;
    }
  }
  if (!error) std::cout << "Total cost: " << sumBuy;
}
#include "ram.h"


std::vector<int> ram;

void write(const std::vector<int>& vec) {
  ram = vec;
}

std::vector<int> read() {
  return ram;
}
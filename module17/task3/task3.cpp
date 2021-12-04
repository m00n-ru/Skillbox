#include <cstring>
#include <iostream>

bool substr(const char* a, const char* b) {
  if (std::strstr(a, b) == nullptr) return false;
  return true;
}

int main() {
  const char* a = "Hello world";
  const char* b = "wor";
  const char* c = "banana";
  std::cout << substr(a, b) << " " << substr(a, c);
}

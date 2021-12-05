#include <cstring>
#include <iostream>

bool substr(const char* a, const char* b) {
  int j = 0;
  bool check = false;
  for (int i = 0; *(a + i) != '\0'; i++) {
    if (*(a + i) == *(b + j)) {
      if (*(b + j + 1) != '\0') {
        j++;
        check = true;
      } else {
        return check;
      }
    } else {
      check = false;
			j=0;
    }
  }
  return check;
}

int main() {
  const char* a = "Hwolo world";
  const char* b = "wor";
  const char* c = "banana";
  std::cout << substr(a, b) << " " << substr(a, c);
}

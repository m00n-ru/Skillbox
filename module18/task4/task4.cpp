#include <iostream>

void evendigits(long long n, int &ans) {
  if (n == 0) return;
  if ((n % 10) % 2 == 0) ++ans;
  evendigits(n / 10, ans);
}

int main() {
  int ans = 0;
  long long n;
  std::cout << "Enter n: ";
  std::cin >> n;
  evendigits(n, ans);
  std::cout << "ans = " << ans;
}
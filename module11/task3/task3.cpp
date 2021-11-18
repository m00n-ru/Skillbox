#include <math.h>

#include <iostream>

int transform(std::string ip) {
  int num = 0;
  for (int i = 0; i < ip.length(); i++) {
    num += (ip[i] - '0') * std::pow(10, ip.length() - 1 - i);
    if (ip.length() > 1 && num == 0) num += 1000;
  }
  return num;
}

bool corrcetSymbol(std::string ip) {
  int pointCount = 0;
  for (int i = 0; i < ip.length(); i++) {
    if (ip[i] == '.') ++pointCount;

    if (ip[i] == '.' || (ip[i] >= '0' && ip[i] <= '9')) {
      continue;
    } else {
      return false;
    }
  }
  if (pointCount != 3) return false;
  return true;
}

bool corrcetIp(std::string ip) {
  if (corrcetSymbol(ip)) {

		for (int i = 0; i < 4; i++) {
      std::string num = ip.substr(0, ip.find('.'));
      if (num.empty() || ip.empty() || num.length() > 3 || transform(num) > 255) {
        return false;
      } else {
        ip.erase(0, ip.find('.') + 1);
      }
    }
		return true;
  } else {
    return false;
  }
}

int main() {
  while (true) {
    std::string ipAddress;
    std::cout << "Enter IP address:" << std::endl;
    std::cin >> ipAddress;

    if (corrcetIp(ipAddress)) {
      std::cout << "IP address is CORRECT";
    } else {
      std::cout << "INVALID IP ADDRESS";
    }
    std::cout << std::endl;
  }
}

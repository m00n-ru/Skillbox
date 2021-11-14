#include <iostream>
#include <math.h>

int transform(std::string ip) {
  int num = 0;
  for (int i = 0; i < ip.length(); i++) {
    num += (ip[i] - '0') * std::pow(10, ip.length() - 1 - i);
    if (num == 0) num += 1000;
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
    std::string num1 = ip.substr(0, ip.find('.'));
    if (num1.empty() || ip.empty() || num1.length() > 3) {
      return false;
    } else {
      ip.erase(0, ip.find('.') + 1);
    }

    std::string num2 = ip.substr(0, ip.find('.'));
    if (num2.empty() || ip.empty() || num2.length() > 3) {
      return false;
    } else {
      ip.erase(0, ip.find('.') + 1);
    }

    std::string num3 = ip.substr(0, ip.find('.'));
    if (num3.empty() || ip.empty() || num3.length() > 3) {
      return false;
    } else {
      ip.erase(0, ip.find('.') + 1);
    }

    if (ip.empty() || ip.find('.') != std::string::npos) {
      return false;
    } else {
      std ::string num4 = ip;
      if (num4.length() > 3) return false;

      if (transform(num1) <= 255 && transform(num2) <= 255 &&
          transform(num3) <= 255 && transform(num4) <= 255) {
        return true;
      } else {
        return false;
      }
    }
  } else {
    return false;
  }
}

int main() {
	std::string ipAddress;
	std::cout << "Enter IP address:" << std::endl;
	std::cin >> ipAddress;

  if (corrcetIp(ipAddress)) {
    std::cout << "IP address is CORRECT";
  } else {
    std::cout << "INVALID IP ADDRESS";
  }
}

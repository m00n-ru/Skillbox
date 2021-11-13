#include <iostream>

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
    if (num1.empty() || ip.empty()) {
      return false;
    } else {
      ip.erase(0, ip.find('.') + 1);
    }

    std::string num2 = ip.substr(0, ip.find('.'));
    if (num2.empty() || ip.empty()) {
      return false;
    } else {
      ip.erase(0, ip.find('.') + 1);
    }

    std::string num3 = ip.substr(0, ip.find('.'));
    if (num3.empty() || ip.empty()) {
      return false;
    } else {
      ip.erase(0, ip.find('.') + 1);
    }

    if (ip.empty() || ip.find('.') != std::string::npos){
      return false;
    } else {
      std::string num4 = ip;
    }

    return true;
  } else {
    return false;
  }
        

	//for (int i = 0; i < ip.length(); i++) {
	//		
	//}


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

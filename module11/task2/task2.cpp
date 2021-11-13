#include <iostream>

// 1 - 64 2 - 63
// eng 1-9 - . !( 1 last ..)
// !#$%&'*+-/+?^_`{|}~

bool engAbcNum(char ch) {
  if (ch >= '0' && ch <= '9' || ch >= 'a' && ch <= 'z' ||
      ch >= 'A' && ch <= 'Z') {
    return true;
  } else {
    return false;
  }
}

bool strCheck(char ch) {
  std::string check = "!#$%&'*+-/+?^_`{|}~";
  for (int i = 0; i < check.length(); i++) {
    if (ch == check[i]) {
      return true;
    }
  }
  return false;
}

bool correctSymbolFirstPart(std::string email) {
  bool flag = true;
  if (email.length() > 64) {
    flag = false;
  } else {
    for (int i = 0; i < email.length() && flag; i++) {
      if ((email[i] == '.' && i != 0 && i != email.length() - 1 && email[i - 1] != '.') 
          || (strCheck(email[i])) || engAbcNum(email[i])) {
        continue;
      } else {
        flag = false;
      }
    }
  }
  return flag;
}

bool correctSymbolSecondPart(std::string email) {
  bool flag = true;
  if (email.length() > 63) {
    flag = false;
  } else {
    for (int i = 0; i < email.length() && flag; i++) {
      if ((email[i] == '.' && i != 0 && i != email.length() - 1 &&
           email[i - 1] != '.') || engAbcNum(email[i]) || email[i] == '-') {
        continue;
      } else {
        flag = false;
      }
    }
  }
  return flag;
}

void correctEmail(std::string email) {
  if (email.find('@') != std::string::npos &&
      email.find('@') == email.rfind('@') && email.find('@') != 0 &&
      email.find('@') < email.length() - 3) {

    std::string firstPart = email.substr(0, email.find('@'));
    std::string secondPart = email.substr(email.find('@') + 1);

    if (correctSymbolFirstPart(firstPart) &&
        correctSymbolSecondPart(secondPart)) {
      std::cout << "YES!!! email is CORRECT";
    } else {
      std::cout << "NO!!! email is INCORRECT";
    }
  } else {
    std::cout << "NO!!! email is INCORRECT";
  }
}

int main(){
  std::string email;
  std::cout << "Enter e-mail:" << std::endl;
  std::cin >> email;
  correctEmail(email);
}

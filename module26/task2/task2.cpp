#include <iostream>
#include <limits>
#include <map>
#include <string>
#include <vector>

class Num {
  std::string num;

public:
  bool check() {
    if (num.length() == 10) {
      std::cout << "Incorrect length num!" << std::endl;
      return false;
    }
    for (auto a : num) {
      if (a < '0' || a > '9') {
        std::cout << "Incorrect symbol num!" << std::endl;
        return false;
      }
    }
    return true;
  }

  void set_num() {
    std::string n;
    std::cin >> n;
    num = n;
  }

  std::string get_num() { return num; }
};

class Book {
  std::map<std::string, std::string> entery;

public:
  void creat() {
    std::string name;
    Num num;
    std::cout << " | Enter name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);
    do {
      std::cout << " | Enter nubmer: +7";
      num.set_num();
    } while (!num.check());
    entery[name] = num.get_num();
  }

  void print_all() {
    for (auto a : entery) {
      std::cout << a.first << " ";
      std::cout << "+7" << a.second << " ";
      std::cout << std::endl;
    }
    if (entery.empty()) {
      std::cout << " | Phonebook empty" << std::endl;
    }
  }

  void find_num(std::string &line) {
    auto it = entery.find(line);
    bool f = false;
    if (it != entery.end()) {
      std::cout << it->first << " +7" << it->second << std::endl;
      f = true;
    } else {
      for (it = entery.begin(); it != entery.end(); it++) {
        if (it->second == line) {
          std::cout << it->first << " +7" << it->second << std::endl;
          f = true;
        }
      }
      if (!f) {
        std::cout << " | Not found" << std::endl;
      }
    }
  }
};

class Phone {
  Book b;

public:
  void add() { b.creat(); }

  void call() {
    std::string line;
    std::cout << " | Enter name or number: ";
    std::cin >> line;
    std::cout << " | CALL ";
    b.find_num(line);
  }

  void sms() {
    std::string line;
    std::string sms;
    std::cout << " | Enter name or number: ";
    std::cin >> line;
    std::cout << " | Enter message: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, sms);
    std::cout << " | SMS ENTER to ";
    b.find_num(line);
  }
};

int main() {
  std::string com;
  Phone *phone = new Phone;
  while (true) {
    std::cout << "Enter command: ";
    std::cin >> com;
    if (com == "add") {
      phone->add();
    } else if (com == "call") {
      phone->call();
    } else if (com == "sms") {
      phone->sms();
    } else if (com == "exit") {
      break;
    } else {
      std::cout << "Error, command" << std::endl;
    }
  }
  delete phone;
  phone = nullptr;
}
#include <iostream>
#include <cpr/cpr.h>


int main() {
  std::string command;
  while (true) {
    std::cout << "Your request(get, post, put, delete, patch): ";
    std::cin >> command;
    cpr::Response r;
    if (command == "get") {
      r = cpr::Get(cpr::Url {"http://httpbin.org/get"});
    } else if (command == "post") {
      r = cpr::Post(cpr::Url {"http://httpbin.org/post"}, cpr::Payload({{"name", "Test_name"}}));
    } else if (command == "put") {
      r = cpr::Put(cpr::Url {"http://httpbin.org/put"}, cpr::Payload({{"name", "Test_name"}}));
    } else if (command == "delete") {
      r = cpr::Delete(cpr::Url {"http://httpbin.org/delete"});
    } else if (command == "patch") {
      r = cpr::Patch(cpr::Url {"http://httpbin.org/patch"}, cpr::Payload({{"name", "Test_name"}}));
    } else if (command == "ext") {
      break;
    } else {
      std::cout << "WARNING: this request is not supported!" << std::endl;
    }

    std::cout << r.text << std::endl;
  }
}

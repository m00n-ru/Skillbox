#include <iostream>
#include <vector>
#include <cpr/cpr.h>

void get(const std::vector<cpr::Pair>&);
void post(const std::vector<cpr::Pair>&);

int main() {
  std::vector<cpr::Pair> request;

  while (true) {
    std::string key;
    std::string value;

    std::cout << "Argument: ";
    std::cin >> key;
    if (key == "post") {
      post(request);
      break;
    } else if (key == "get") {
      get(request);
      break;
    }
    std::cout << "Value: ";
    std::cin >> value;
    cpr::Pair pArg = {key.c_str(),value.c_str()};
    request.push_back(pArg);
  }
}

void get(const std::vector<cpr::Pair>& req) {
  std::string urlGet = "http://httpbin.org/get?";
  for (auto& i : req) {
    urlGet += i.key + "=" + i.value + "&";
  }
  urlGet.erase(urlGet.end() - 1);
  std::cout << cpr::Get(cpr::Url {urlGet.c_str()}).text << std::endl;
}

void post(const std::vector<cpr::Pair>& req) {
  std::cout << cpr::Post(cpr::Url {"http://httpbin.org/post"},
                         cpr::Payload(req.begin(), req.end())).text << std::endl;
}

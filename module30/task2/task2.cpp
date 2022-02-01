#include <iostream>
#include <cpr/cpr.h>


int main() {
  cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/html"), cpr::Header({{"accept","text/html"}}));

  std::string header = r.text;
  int begin = 0;
  int end = 0;

  if (header.find("<h1>") != std::string::npos) {
    begin = header.find("<h1>") + 4;
  }

  if (header.find("</h1>") != std::string::npos) {
    end = header.find("</h1>") - begin;
  }

  std::cout << header.substr(begin, end) << std::endl;
}



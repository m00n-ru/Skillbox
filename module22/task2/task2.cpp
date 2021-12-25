#include <map>
#include <iostream>
#include <string>

int main() {
	std::string input;
	std::map<std::string, std::string> reg;

	while (true) {
		std::cout << "Enter: ";
		std::cin >> input;

		if (input == "Next") {
			std::cout << "Next: " << reg.begin()->second << std::endl;
			reg.erase(reg.begin());
		} else if (input == "q") {
			break;
		} else {
			std::pair<std::map<std::string, std::string>::iterator, bool> number;
			number = reg.insert({input, input});
			if (!number.second) {
				int count = 1;
				std::string repit = input;
				while (true) {
					++number.first;
					repit = input + std::to_string(count);
					if (number.first == reg.end() || number.first->first != repit) {
						reg[repit] = input;
						break;
					}
					++count;
				}
			}
		}
	}
	std::cout << std::endl;
	for (std::pair<std::string, std::string> i : reg) {
		std::cout << i.second << std::endl;
	}
}

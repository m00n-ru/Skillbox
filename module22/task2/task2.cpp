#include <map>
#include <iostream>
#include <string>

int main() {
	std::string input;
	std::map<std::string, int> reg;

	while (true) {
		std::cout << "Enter: ";
		std::cin >> input;

		if (input == "Next") {
			if (reg.empty()) {
				std::cout << "The queue is empty" << std::endl;
				continue;
			}
			std::cout << "Next: " << reg.begin()->first << std::endl;
			if (reg.begin()->second == 1) {
				reg.erase(reg.begin());
			} else {
				--reg.begin()->second;
			}
		} else if (input == "q") {
			break;
		} else {
			std::pair<std::map<std::string, int>::iterator, bool> pair_input = reg.insert({input, 1});
			if (!pair_input.second) {
				++pair_input.first->second;
			}
		}
	}
	std::cout << std::endl;
	for (const std::pair<std::string, int> i : reg) {
		std::cout << i.first << " " << i.second << std::endl;
	}
}

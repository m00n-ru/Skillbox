#include <iostream>
#include <string>
#include <map>
#include <vector>

bool check_num(const std::string& command) {
	for (const char i : command) {
		if ((i >= '0' && i <= '9') || i == '-') {
			continue;
		} else {
			return false;
		}
	}
	return true;
}

void addPhone(std::string& command, std::map<std::string, std::string>& numberToSurname, std::map<std::string, std::vector<std::string>>& surnameToNumber) {
	std::string num = command.substr(0, command.find(' '));
	std::string name = command.substr(command.find(' ') + 1, command.length());

	numberToSurname.insert(std::make_pair(num, name));

	std::pair<std::map<std::string, std::vector<std::string>>::iterator, bool> pair_input;
	std::vector<std::string> num_pool = {num};
	pair_input = surnameToNumber.insert({name, num_pool});
	if (!pair_input.second) {
		for (std::string& i : pair_input.first->second) {
			if(i == num) {
				return;
			}
		}
		pair_input.first->second.push_back(num);
	}

}

std::string request_surname(std::string& command, std::map<std::string, std::string>& numberToSurname) {
	std::string str;
	if (numberToSurname.find(command) == numberToSurname.end()) {
		str = "Not found in the list.";
	} else {
		std::map<std::string, std::string>::iterator it = numberToSurname.find(command);
		str = it->second;
	}
	return str;
}

std::string request_number(std::string& command, std::map<std::string, std::vector<std::string>>& surnameToNumber) {
	std::string str;
	if (surnameToNumber.find(command) == surnameToNumber.end()) {
		str = "Not found in the list.";
	} else {
		std::map<std::string, std::vector<std::string>>::iterator it = surnameToNumber.find(command);
		for(std::string& i : it->second) {
			str += i + " ";
		}
	}
	return str;
}

int main() {
	std::map<std::string, std::string> numberToSurname;
	std::map<std::string, std::vector<std::string>> surnameToNumber;

	while (true) {
		std::cout << "Command: ";
		std::string command;
		std::getline(std::cin, command);

		if (command.find(' ') != std::string::npos) {
			addPhone(command, numberToSurname, surnameToNumber);
		} else if (check_num(command)) {
			std::cout << request_surname(command, numberToSurname) << std::endl;
		} else {
			std::cout << request_number(command, surnameToNumber) << std::endl;
		}
	}
}

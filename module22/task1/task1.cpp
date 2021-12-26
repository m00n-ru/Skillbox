#include <iostream>
#include <string>
#include <map>

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

void addPhone(std::string& command, std::map<std::string, std::string>& numberToSurname, std::map<std::string, std::string>& surnameToNumber) {
	std::string num = command.substr(0, command.find(' '));
	std::string name = command.substr(command.find(' ') + 1, command.length());

	numberToSurname.insert(std::make_pair(num, name));

	if (surnameToNumber.find(name) == surnameToNumber.end()) {
		surnameToNumber.insert(std::make_pair(name, num));
	} else {
		std::string str = surnameToNumber.find(name)->second;
		if (str.find(num) == std::string::npos) {
			str = str + " " + num;
			surnameToNumber[name] = str;
		}
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

std::string request_number(std::string& command, std::map<std::string, std::string>& surnameToNumber) {
	std::string str;
	if (surnameToNumber.find(command) == surnameToNumber.end()) {
		str = "Not found in the list.";
	} else {
		std::map<std::string, std::string>::iterator it = surnameToNumber.find(command);
		str = it->second;
	}
	return str;
}

int main() {
	std::map<std::string, std::string> numberToSurname;
	std::map<std::string, std::string> surnameToNumber;

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

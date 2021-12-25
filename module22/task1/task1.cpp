#include <map>
#include <iostream>
#include <string>

int main() {
	std::map<int, std::string> phonebook;
	phonebook.insert(std::make_pair(111111, "Ivanov"));
	phonebook.insert(std::make_pair(222222, "Sidorov"));
	phonebook.insert(std::make_pair(333333, "Petrov"));
	phonebook.insert(std::make_pair(123123, "Ivanov"));
	phonebook.insert(std::make_pair(232323, "Vasiliev"));
	phonebook.insert(std::make_pair(666666, "Ivanov"));

	std::string com; // xx-xx-xx surname
	bool check = true;
	int num = 0;
	std::string surname;

	std::cout << "Enter command:";
	getline(std::cin, com);

	for (char& i : com) {
		if (std::isdigit(com[0])) {
			if (i >= '0' && i <= '9' && check) {
				num *= 10;
				num += ((int)i - '0');
			}
			if (!check) surname += i;
			if (i == ' ') check = false;
		}
		else {
			surname += i;
		}
	}

	if (!check) {
		if (!phonebook.insert(std::make_pair(num, surname)).second) std::cout << "Error the number is already registered";
		phonebook.insert(std::make_pair(num, surname));

		for (std::pair<int, std::string> i : phonebook) {
			std::cout << i.first / 10000 << "-" << (i.first / 100) % 100
				<< "-" << i.first % 100 << " ";
			std::cout << i.second << std::endl;
		}
	}
	else if (num != 0) {
		if (phonebook.find(num) != phonebook.end()) {
			std::cout << "Number found:" << std::endl;
			std::cout << phonebook.find(num)->first << " " << phonebook.find(num)->second;
		}
		else {
			std::cout << "Number not found:" << std::endl;
		}
	}
	else {
		std::cout << "Number with surname:" << std::endl;
		for (std::pair<int, std::string> i : phonebook) {
			if (i.second == surname) {
				std::cout << " " << i.first << std::endl;
			}
		}
	}
}

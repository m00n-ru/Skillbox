#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

struct payout {
	std::string name;
	std::string surname;
	std::string date;
	double summary = 0;
};

void add(std::ofstream& file) {
	payout line;
	std::cout << "Enter name: ";
	std::cin >> line.name;

	std::cout << "Enter surname: ";
	std::cin >> line.surname;

	while (true) {
		std::cout << "Enter date (format dd.mm.yyyy): ";
		std::string date_string;
		std::cin >> date_string;
		try {
			int day = std::stoi(date_string.substr(0, 2));
			if (day < 1 || day > 31) throw 1;
			int month = std::stoi(date_string.substr(3, 2));
			if (month < 1 || month > 12) throw 2;
			int year = std::stoi(date_string.substr(6, 4));
			if (year < 1990 || year > 2022) throw 3;
			if (date_string.length() != 10) throw 4;
			line.date = std::to_string(day) + "." + std::to_string(month) + "." + std::to_string(year);
			break;
		}
		catch (std::exception) {
			std::cout << "Error, repit" << std::endl;
			continue;
		}
		catch (int) {
			std::cout << "Error, repit" << std::endl;
			continue;
		}
	}

	while (true) {
		std::cout << "Enter summary: ";
		std::string pay_string;
		std::cin >> pay_string;
		try {
			line.summary = std::stod(pay_string);
			break;
		}
		catch (std::invalid_argument) {
			std::cout << "Error, repit" << std::endl;
			continue;
		}
	}
	file << line.name << " " << line.surname << " " << line.date << " " << line.summary << std::endl;
	std::cout << "add file" << std::endl;
	file.close();
}

void list(std::ifstream& file) {
	payout line;
	int num = 1;
	std::cout.setf(std::ios::left, std::ios::adjustfield);
	std::cout.width(3);
	std::cout << "#" << " | ";
	std::cout.width(10);
	std::cout << "Name" << " | ";
	std::cout.width(10);
	std::cout << "Surname" << " | ";
	std::cout.width(10);
	std::cout << "Date" << " | " << "Summary payout" << std::endl;
	std::cout << "---------------------------------------------------------" << std::endl;
	while (file >> line.name >> line.surname >> line.date >> line.summary) {
		std::cout.setf(std::ios::left, std::ios::adjustfield);
		std::cout.width(3);
		std::cout << num++ << " | ";
		std::cout.width(10);
		std::cout << line.name << " | ";
		std::cout.width(10);
		std::cout << line.surname << " | ";
		std::cout.width(10);
		std::cout << line.date << " | " << line.summary << std::endl;
	}
}

int main() {
	std::string comm;
	std::cout << "Enter command list, add or exit: ";
	while (std::getline(std::cin, comm)) {
		if (comm == "list") {
			std::ifstream file_out("paylist.txt");
			list(file_out);
			file_out.close();
		} else if (comm == "add") {
			std::ofstream file_in("paylist.txt", std::ios::app);
			add(file_in);
			file_in.close();
		} else if (comm == "exit") {
			break;
		} else {
			std::cout << "Error command" << std::endl;
		}
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Enter command list, add or exit: ";
	}
}

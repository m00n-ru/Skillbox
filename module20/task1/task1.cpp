#include <fstream>
#include <iostream>
#include <string>

int main() {
	std::string name;
	std::string surname;
	std::string date;
	std::string summary;
	double sum_payout = 0;
	std::string outdata;
	double payout = 0;

	std::ofstream file("file.txt", std::ios::app);
	while (true) {

		std::cout << "Enter name: ";
		std::cin >> name;
		if (name == "save") {
			file << "Total paid: " << sum_payout;
			file.close();
			break;
		}
		std::cout << "Enter surname: ";
		std::cin >> surname;

		while (true) {
			std::cout << "Enter summary: ";
			std::cin >> summary;
			try {
				payout = std::stod(summary);
				break;
			}
			catch (std::invalid_argument) {
				std::cout << "Error, repit" << std::endl;
				continue;
			}
		}
		sum_payout += payout;

		while (true) {
			std::cout << "Enter date (format dd.mm.yyyy): ";
			std::cin >> date;
			try {
				const int day = std::stoi(date.substr(0, 2));
				if (day < 1 || day > 31) throw 1;
				const int month = std::stoi(date.substr(3, 2));
				if (month < 1 || month > 12) throw 2;
				const int year = std::stoi(date.substr(6, 4));
				if (year< 1990 || year > 2021) throw 3;
				if (date.length() != 10) throw 4;
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

		std::cout << "Enter \"save\" to save and exit or resume" << std::endl;
		outdata += name + " " + surname + " " + date + " " + summary;
		file << outdata << std::endl;
		outdata = "";
	}
}

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>

void initAtm() {
	std::srand(std::time(nullptr));
	int maxBNotes = 1000;
	int sum = 0;
	std::vector<int> bNotes = {0, 0, 0, 0, 0, 0}; // 5000, 2000, 1000, 500, 200, 100
	for (int i = 0; i < maxBNotes; i++) {
		int r = rand() % 6;
		++bNotes[r];
		switch (r) {
			case 0:
				sum += 5000;
				break;
			case 1:
				sum += 2000;
				break;
			case 2:
				sum += 1000;
				break;
			case 3:
				sum += 500;
				break;
			case 4:
				sum += 200;
				break;
			case 5:
				sum += 100;
				break;
		}
	}
	std::ofstream file("atm.bin", std::ios::binary);
	file.write((char*)&sum, sizeof(sum));
	for (const int i : bNotes) {
		file.write((char*)&i, sizeof(i));
	}
	file.close();
}

int correctSum(std::string sum) {
	int sumCorr;
	try {
		sumCorr = std::stoi(sum);
		return sumCorr;
	}
	catch (std::exception) {
		std::cout << "Incorrect data type";
		return -1;
	}
	if (sumCorr % 100 != 0) {
		std::cout << "The sum is a multiple of 100";
		return -1;
	}
}

void newStatusAtm(int sum, std::vector<int> bNotes) {
	std::ofstream file("atm.bin", std::ios::binary);
	file.write((char*)&sum, sizeof(sum));
	for (const int i : bNotes) {
		file.write((char*)&i, sizeof(i));
	}
	file.close();
}

void cashout(int sum) {
	std::ifstream file("atm.bin", std::ios::binary);
	int mSum;
	file.read((char*)&mSum, sizeof(int));

	if (mSum < sum) {
		std::cout << "Insufficient funds in ATMs";
		return;
	}

	std::vector<int> bNotesAtm(6);
	for (int i = 0; i < 6; i ++) {
		file.read((char*)&bNotesAtm[i], sizeof(int));
	}

	std::cout << "Cashout" << std::endl;
	for (int i = 0; i < 6; i ++) {
		int bNotes;
		switch (i) {
			case 0:
				bNotes = 5000;
				break;
			case 1:
				bNotes = 2000;
				break;
			case 2:
				bNotes = 1000;
				break;
			case 3:
				bNotes = 500;
				break;
			case 4:
				bNotes = 200;
				break;
			case 5:
				bNotes = 100;
				break;
		}
		if (sum / bNotes == 0) {
			continue;
		} else if (sum / bNotes <= bNotesAtm[i]) {
			std::cout << bNotes << ": " << sum / bNotes << std::endl;
			bNotesAtm[i] -= sum / bNotes;
			sum -= bNotes * (sum / bNotes);
		} else {
			std::cout << bNotes << ": " << bNotesAtm[i] << std::endl;
			sum -= bNotes * bNotesAtm[i];
			bNotesAtm[i] = 0;
		}
	}
	file.close();
	newStatusAtm(sum, bNotesAtm);
}

int main() {
	std::string oper;
	std::cout << "Enter:" << std::endl;
	std::cout << "+ initialization ATM" << std::endl;
	std::cout << "- cashout" << std::endl;
	std::cin >> oper;
	if (oper == "+") {
		initAtm();
		std::cout << "Initialization ATM: complite" << std::endl;
	} else if (oper == "-") {
		std::string sum;
		std::cout << "Enter the amount you want to withdraw " << std::endl;
		std::cin >> sum;
		if (correctSum(sum) == -1) return 1;
		cashout(correctSum(sum));
	} else {
		std::cout << "incorrect input" << std::endl;
	}

	
}

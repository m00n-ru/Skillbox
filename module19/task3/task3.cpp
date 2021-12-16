#include <iostream>
#include <fstream>
#include <vector>
#include <string>


int main() {
	std::ifstream file;
	std::vector<std::vector<std::string>> tablePay;
	std::vector<std::string> man(4);
	float sumP = 0;
	int id = 0;
	int i = 0;

	file.open(".\\text.txt");

	while (file >> man[0] >> man[1] >> man[2] >> man[3]) {
		tablePay.push_back(man);
		++i;
	}

	float max = std::stof(tablePay[0][2]);
	for (int i = 0; i < tablePay.size(); i++) {
		if (std::stof(tablePay[i][2]) > max) {
			id = i;
			max = std::stof(tablePay[i][2]);
		}
		sumP += std::stof(tablePay[i][2]);
	}

	std::cout << "Amount: " <<  sumP << std::endl;
	std::cout << "Maximum payout: " << tablePay[id][0] << " " << tablePay[id][1];
	file.close();
}
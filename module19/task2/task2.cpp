#include <iostream>
#include <fstream>

int main() {
	std::ifstream file;
	std::string pathF;
	char s[30];

	do {
		std::cout << "File path: ";
		std::cin >> pathF;
		file.open(pathF, std::ios::binary);
		if (!file.is_open()) std::cout << "Error file path!" << std::endl;
	} while (!file.is_open());

	while (file.read(s, sizeof(s) - 1)) {
		s[file.gcount()] = '\0';
		std::cout << s;
	}

	file.close();
}

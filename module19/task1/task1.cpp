#include <iostream>
#include <fstream>

int main() {
	std::string word;
	std::ifstream file;
	int count = 0;
	file.open(".\\words.txt", std::ios::binary);

	std::cout << "Enter word: ";
	std::cin >> word;
	while (!file.eof()) {
		std::string fWord;
		file >> fWord;
		if (fWord == word) ++count;
	}
	std::cout << "Number of words " << word  << ": " << count;
	file.close();
}

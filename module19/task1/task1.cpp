#include <iostream>
#include <fstream>

int main() {
	std::string word;
	std::ifstream file;
	std::string fWord;

	int count = 0;
	file.open(".\\words.txt");

	std::cout << "Enter word: ";
	std::cin >> word;
	while (file >> fWord) { if (fWord == word) ++count; }

	std::cout << count;
	file.close();
}

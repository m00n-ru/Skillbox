#include <map>
#include <iostream>

std::map<char, int> count_char(std::string& st) {
	std::map<char, int> count;
	for (char& i : st) {
		std::pair<std::map<char, int>::iterator, bool> pair_input;
		pair_input = count.insert({i, 1});
		if (!pair_input.second) {
			++pair_input.first->second;
		}
	}
	return count;
}

bool anagram(std::string& st1, std::string& st2) {
	std::map<char, int> count_char_str1 = count_char(st1);
	std::map<char, int> count_char_str2 = count_char(st2);
	return count_char_str1 == count_char_str2;
}

int main() {
	std::string input1;
	std::string input2;

	std::cout << "Enter string 1:";
	std::cin >> input1;
	std::cout << "Enter string 2:";
	std::cin >> input2;

	std::cout << (anagram(input1, input2) ? "Yes" : "No");
}

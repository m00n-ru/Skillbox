#include <map>
#include <iostream>

bool anagram(std::string& st1, std::string& st2) {
	std::map<int, bool> str;
	std::pair<std::map<int, bool>::iterator, bool> pair_chr;

	for (char& i : st1) {
		pair_chr = str.insert({(int)i * 100, true});
		if (!pair_chr.second) {
			int count = 1;
			int repit = (int)i;
			while (true) {
				++pair_chr.first;
				repit = (int)i * 100 + count;
				if (pair_chr.first == str.end() || pair_chr.first->first != repit) {
					str[repit] = true;
					break;
				}
				++count;
			}
		}

	}

	for (char& i : st2) {
		int int_i = (int)i * 100;

		while (true) {
			if (str.find(int_i) != str.end()) {
				if (str.find(int_i)->second) {
					str.find(int_i)->second = false;
					break;
				} else {
					++int_i;
				}
			} else {
				return false;
			}
			return true;
		}
	}
}

int main() {
	std::string input1;
	std::string input2;

	std::cout << "Enter string 1:";
	std::cin >> input1;
	std::cout << "Enter string 2:";
	std::cin >> input2;

	if (anagram(input1, input2)) {
		std::cout << "Yes";
	} else {
		std::cout << "No";
	}
}

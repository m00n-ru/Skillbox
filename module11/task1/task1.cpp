#include <iostream>
#include <string>

std::string encrypt_caesar(std::string text, int param) {
	//A - 65 Z - 90 a - 97 z - 122
	int shiftChar = param % 26;
	for (int i = 0; i < text.length(); i++) {
		if (text[i] >= 'A' && text[i] <= 'Z') {
			if (text[i] + shiftChar > 90) {
				text[i] = text[i] + shiftChar - 26;
			}
			else if (text[i] + shiftChar < 65) {
				text[i] = text[i] + shiftChar + 26;
			}
			else {
				text[i] = text[i] + shiftChar;
			}
		}
		else if (text[i] >= 'a' && text[i] <= 'z') {
			if (text[i] + shiftChar > 122) {
				text[i] = text[i] + shiftChar - 26;
			}
			else if (text[i] + shiftChar < 97) {
				text[i] = text[i] + shiftChar + 26;
			}
			else {
				text[i] = text[i] + shiftChar;
			}
		}
	}
	return text;
}

std::string decrypt_caesar(std::string text, int param) {
	return encrypt_caesar(text, -param);
}

int main() {
	std::string text;
	int param;
	std::cout << "Input text:" << std::endl;
	std::getline(std::cin, text);
	std::cout << "Input the cipher parameter:" << std::endl;
	std::cin >> param;

	std::cout << "Encrypt:" << std::endl;
	std::cout << encrypt_caesar(text, param) << std::endl;
	std::cout << "Decrypt:" << std::endl;
	std::cout << decrypt_caesar(encrypt_caesar(text, param), param) << std::endl;

}





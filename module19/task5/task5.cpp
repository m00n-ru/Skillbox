#include <fstream>
#include <iostream>
#include <limits>
#include <string>

void question(int sectorNum, int& tvP, int& plP) {
	std::string textQ;
	std::string textA;
	std::string answerUser;

	std::ifstream quest;
	std::ifstream answer;
	std::string pathQ = ".\\sectors\\question" + std::to_string(sectorNum) + "\\question.txt";
	std::string pathA = ".\\sectors\\question" + std::to_string(sectorNum) + "\\answer.txt";

	quest.open(pathQ);
	while (std::getline(quest, textQ)) std::cout << textQ << std::endl;
	answer.open(pathA);
	std::getline(answer, textA);

	std::cout << "Enter answer: ";
	std::cin >> answerUser;

	if (answerUser == textA) {
		std::cout << "Point to player" << std::endl;
		++plP;
	} else {
		std::cout << "Point to TV viewers" << std::endl;
		std::cout << "Correct answer: " << textA << std::endl;
		++tvP;
	}

	quest.close();
	answer.close();
}

int main() {
	bool sectors[13]{};
	int sectorInput;
	int tvPoint = 0;
	int plPoint = 0;

	std::cout << "Start game" << std::endl;

	while (tvPoint != 6 && plPoint != 6) {
		std::cout << "Enter sector (1-13): ";
		while (!(std::cin >> sectorInput) || sectorInput < 1 || sectorInput > 13) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Error input" << std::endl;
		}
		int s = sectorInput - 1;

		while (sectors[s]) {
			if (s < 12) {
				++s;
			} else {
				s = 0;
			}
		}
		std::cout << "Question from sector number: " << s + 1 << std::endl;
		sectors[s] = true;
		question(s + 1, tvPoint, plPoint);
	}

	if (tvPoint == 6)
		std::cout << "TV viewers WIN !!!";
	else
		std::cout << "Player WIN !!!";
}

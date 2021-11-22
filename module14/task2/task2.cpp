#include <iostream>

void printField(char xo[][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << xo[i][j];
			if (j < 2) std::cout << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void newGame(char xo[][3]) {
	char space = ' ';
	std::cout << "New game" << std::endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			xo[i][j] = space;
		}
	}
}

bool checkWin(char xo[][3], int x, int y) {
	int sum1 = 0;
	int sum2 = 0;

	for (int i = 0; i < 3; i++) {
		sum1 += xo[x][i];
		sum2 += xo[i][y];
	}
	if (sum1 == 264 || sum1 == 237 || sum2 == 264 || sum2 == 237) return true;

	return false;
}

int main() {
	char xo[3][3];
	bool step = true;
	int x, y;
	int count = 0;

	newGame(xo);
	while (true) {
		std::cout << "Enter the coordinates x(1-3), y(1-3): ";
		std::cin >> x >> y;
		if (xo[x - 1][y - 1] == ' ' && x > 0 && x <= 3 && y > 0 && y <= 3) {
			if (step) {
				xo[x - 1][y - 1] = 'X';
				step = false;
			} else {
				xo[x - 1][y - 1] = 'O';
				step = true;
			}
			printField(xo);
			if (checkWin(xo, x - 1, y - 1)) {
				std::cout << "+++++++++++" << std::endl;
				std::cout << "+ WIN !!! +" << std::endl;
				std::cout << "+++++++++++" << std::endl;
				break;
			}
			++count;
			if (count == 9) {
				std::cout << "Friendship won!" << std::endl;
				break;
			}
		} else {
			std::cout << "ERROR" << std::endl;
		}
	}
}
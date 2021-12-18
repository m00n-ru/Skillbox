#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

int main() {
	int w, h;
	std::ofstream file("pic.txt");
	std::srand(std::time(nullptr));
	std::cout << "Enter width and high: ";
	std::cin >> w >> h;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			int num = std::rand()%2;
			file << num;
		}
		file << std::endl;
	}
}

#include <iostream>
#include <fstream>

int main() {
	std::ifstream river(".\\river.txt");
	std::ofstream basket(".\\basket.txt", std::ios::app);

	std::cout << "Enter the name of the fish: ";
	std::string fish;
	std::cin >> fish;

	int countFish = 0;
	while (river) {
		std::string fishInRiver;
		river >> fishInRiver;

		if (fish == fishInRiver) {
			basket << fishInRiver << std::endl;
			++countFish;
		}
	}

	if (countFish != 0)
		std::cout << "You caught " << countFish << " fishes of " << fish;
	else
		std::cout << "You didn't catch any fish";

	river.close();
	basket.close();
	return 0;
}

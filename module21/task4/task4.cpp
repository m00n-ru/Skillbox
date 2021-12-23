#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iomanip>

struct Character {
	std::string name;
	bool dead = false;
	int hp;
	int armor;
	int damage;
	int x;
	int y;
};

Character player;
std::vector<Character> nps(5);
int width = 42;
int length = 42;

int cord_gen(std::vector<int>& cord_pool) {
	while (true) {
		int cord = std::rand() % (width - 2) + 1;
		for (int i : cord_pool) {
			if (cord != i) return cord;
		}
	}
}

void setup() {
	std::srand(std::time(nullptr));
	int count = 1;
	std::vector<int> x_cord{0};
	std::vector<int> y_cord{0};

	for (Character& nps_unit : nps) {
		nps_unit.name = "Enemy #";
		nps_unit.name += std::to_string(count++);
		nps_unit.hp = std::rand() % 101 + 50;
		nps_unit.armor = std::rand() % 51;
		nps_unit.damage = std::rand() % 16 + 15;

		nps_unit.x = cord_gen(x_cord);
		x_cord.push_back(nps_unit.x);
		nps_unit.y = cord_gen(y_cord);
		y_cord.push_back(nps_unit.y);
	}

	std::cout << "Create hero:" << std::endl;
	std::cout << "1. Name hero: ";
	std::cin >> player.name;
	while (true) {
		std::string input;
		try {
			std::cout << "2. Heals point: ";
			std::cin >> input;
			player.hp = std::stoi(input);
			std::cout << "3. Armor: ";
			std::cin >> input;
			player.armor = std::stoi(input);
			std::cout << "4. damage: ";
			std::cin >> input;
			player.damage = std::stoi(input);
			break;
		}
		catch (std::exception) {
			std::cout << "Incorrect data type" << std::endl;
			continue;
		}
	}

	player.x = cord_gen(x_cord);
	player.y = cord_gen(y_cord);
}

void drow() {
	system("cls");

	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width + 1; j++) {
			// game field
			if (j < width) {
				bool empty = true;
				if (i == 0 || i == length - 1) {
					std::cout << '#';
				} else if (j == 0 || j == width - 1) {
					std::cout << "#";
				} else {

					for (Character cord : nps) {
						if (!cord.dead && i == cord.x && j == cord.y) {
							std::cout << "E";
							empty = false;
						}
					}

					if (!player.dead && i == player.x && j == player.y) {
						std::cout << "P";
						empty = false;
					}

					if (empty) std::cout << ".";
				}
			}
			// info game
			if (j == width) {
				std::cout << "     ";
				if (i == 1) std::cout << "Herro: " << player.name;
				if (i == 3) std::cout << "hp: " << player.hp;
				if (i == 4) std::cout << "armor: " << player.armor;
				if (i == 5) std::cout << "damage: " << player.damage;
				if (i == 6) std::cout << "x: " << player.x;
				if (i == 7) std::cout << "y: " << player.y;

				if (i == 10) std::cout << "NPS";
				if (i >= 12 && i <= 16)
					std::cout << nps[i - 12].name << " hp: " << std::setw(3) << nps[i - 12].hp << " a: " <<
							std::setw(2) << nps[i - 12].armor << " d: " << std::setw(2) << nps[i - 12].damage <<
							" x:" << std::setw(2) << nps[i - 12].x << " y:" << std::setw(2) << nps[i - 12].y;

			}
		}
		std::cout << std::endl;
	}
}

void input() {

}

void logic() {

}

void move_nps() {

}

void save_game() {

}

void load_game() {

}

int main() {
	setup();
	drow();
}

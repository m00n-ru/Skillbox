#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <conio.h>

struct Character {
	std::string name = "Noname";
	bool dead = false;
	int hp = 100;
	int armor = 100;
	int damage = 40;
	int x = 5;
	int y = 5;
};

Character player;
std::vector<Character> nps(5);
int width = 42;
int length = 42;
bool status_game = true;
bool hit_nps = false;
bool hit_hero = false;
std::string status_string;

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
		nps_unit.name = "Enemy_#";
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
	std::cout << "Press any key to start game";
}

void draw() {
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

					for (Character& cord : nps) {
						if (!cord.dead && i == cord.y && j == cord.x) {
							std::cout << "E";
							empty = false;
						}
					}

					if (!player.dead && i == player.y && j == player.x) {
						std::cout << "P";
						empty = false;
					}

					if (empty) std::cout << ".";
				}
			}
			// info game
			if (j == width) {
				std::cout << "     ";
				std::cout.setf(std::ios::left);
				if (i == 1) std::cout << "Hero: " << player.name;
				if (i == 3) std::cout << std::setw(8) << "HP: " << player.hp;
				if (i == 4) std::cout << std::setw(8) << "ARMOR: " << player.armor;
				if (i == 5) std::cout << std::setw(8) << "Damage: " << player.damage;
				if (i == 6) std::cout << "x: " << player.x;
				if (i == 7) std::cout << "y: " << player.y;

				if (i == 10) std::cout << "NPS";
				if (i >= 12 && i <= 16)
					if (nps[i - 12].dead) {
						std::cout << nps[i - 12].name << " DEAD";
					} else {
						std::cout << nps[i - 12].name << " hp: " << std::setw(3) << nps[i - 12].hp
								<< " a: " << std::setw(2) << nps[i - 12].armor << " d: " << std::setw(2)
								<< nps[i - 12].damage << " x:" << std::setw(2) << nps[i - 12].x << " y:"
								<< std::setw(2) << nps[i - 12].y;
					}

				if (i == 20) std::cout << "Control keys:";
				if (i == 21) std::cout << "W, S, A, D - up, down, left, right";
				if (i == 23) std::cout << "Q - quit game";
				if (i == 24) std::cout << "Z - save game";
				if (i == 25) std::cout << "X - load game";

				if (i == 28) {
					if (hit_nps) std::cout << "HIT NPS";
					if (hit_hero) std::cout << "HIT HERO";
				}

			}
		}
		std::cout << std::endl;
	}
}

void save_game() {
	std::ofstream save("save.bin", std::ios::binary);

	save << player.name << std::endl;
	save << player.dead << std::endl;
	save << player.hp << std::endl;
	save << player.armor << std::endl;
	save << player.dead << std::endl;
	save << player.x << std::endl;
	save << player.y << std::endl;

	for (Character& i : nps) {
		save << i.name << std::endl;
		save << i.dead << std::endl;
		save << i.hp << std::endl;
		save << i.armor << std::endl;
		save << i.dead << std::endl;
		save << i.x << std::endl;
		save << i.y << std::endl;
	}

	save.close();
}

void status_check() {
	int all_nps = 0;
	if (player.dead) {
		status_game = false;
		status_string = "HERO LOSE";
		return;
	}

	for (Character& nps_unit : nps) {
		if (nps_unit.dead) {
			all_nps += 1;
			nps_unit.x = 0;
			nps_unit.y = 0;
		}
	}
	if (all_nps == 5) {
		status_game = false;
		status_string = "HERO WIN";
	}
}

void load_game() {
	std::ifstream save("save.bin", std::ios::binary);

	save >> player.name;
	save >> player.dead;
	save >> player.hp;
	save >> player.armor;
	save >> player.dead;
	save >> player.x;
	save >> player.y;

	for (Character& i : nps) {
		save >> i.name;
		save >> i.dead;
		save >> i.hp;
		save >> i.armor;
		save >> i.dead;
		save >> i.x;
		save >> i.y;
	}
	status_check();
	save.close();
}

void damage(Character& target, Character& hit) {
	int remains_damage = 0;
	if (target.armor > 0) {
		target.armor -= hit.damage;
		if (target.armor < 0) {
			remains_damage = hit.damage - target.armor;
			target.armor = 0;
		}
	} else {
		if (remains_damage > 0) {
			target.hp -= remains_damage;
		} else {
			target.hp -= hit.damage;
		}
	}
	if (target.hp <= 0) {
		target.dead = true;
	}
}

void input() {
	bool check_nps = false;
	hit_hero = false;
	switch (_getch()) {
		case 'a': {
			for (Character& nps_check : nps) {
				if (player.x - 1 == nps_check.x && player.y == nps_check.y) {
					check_nps = true;
					damage(nps_check, player);
					hit_hero = true;
					break;
				}
			}
			if (!check_nps) {
				player.x -= 1;
			}
			if (player.x == 0) player.x = 1;
			break;
		}
		case 'd': {
			for (Character& nps_check : nps) {
				if (player.x + 1 == nps_check.x && player.y == nps_check.y) {
					check_nps = true;
					damage(nps_check, player);
					hit_hero = true;
					break;
				}
			}
			if (!check_nps) {
				player.x += 1;
			}
			if (player.x == width - 1) player.x = width - 2;
			break;
		}
		case 'w': {
			for (Character& nps_check : nps) {
				if (player.x == nps_check.x && player.y - 1 == nps_check.y) {
					check_nps = true;
					damage(nps_check, player);
					hit_hero = true;
					break;
				}
			}
			if (!check_nps) {
				player.y -= 1;
			}
			if (player.y == 0) player.y = 1;
			break;
		}
		case 's': {
			for (Character& nps_check : nps) {
				if (player.x == nps_check.x && player.y + 1 == nps_check.y) {
					check_nps = true;
					damage(nps_check, player);
					hit_hero = true;
					break;
				}
			}
			if (!check_nps) {
				player.y += 1;
			}
			if (player.y == length - 1) player.y = length - 2;
			break;
		}
		case 'q': {
			status_game = false;
			status_string = "EXIT GAME";
			break;
		}
		case 'z': {
			save_game();
			break;
		}
		case 'x': {
			load_game();
			draw();
			break;
		}
	}
}

void move_nps() {
	for (Character& nps_unit : nps) {
		if (nps_unit.dead) continue;

		hit_nps = false;
		int m = rand() % 4; // 0-l 1-r 2-u 3-d
		bool check_nps = false;
		bool check_player = false;
		switch (m) {
			case 0: {
				for (Character& nps_check : nps) {
					if (nps_unit.x - 1 == nps_check.x && nps_unit.y == nps_check.y) {
						check_nps = true;
						break;
					}
				}
				if (nps_unit.x - 1 == player.x && nps_unit.y == player.y) {
					check_player = true;
					damage(player, nps_unit);
					hit_nps = true;
				}
				if (!check_nps && !check_player) nps_unit.x -= 1;
				if (nps_unit.x == 0) nps_unit.x = 1;
				break;
			}
			case 1: {
				for (Character& nps_check : nps) {
					if (nps_unit.x + 1 == nps_check.x && nps_unit.y == nps_check.y) {
						check_nps = true;
						break;
					}
				}
				if (nps_unit.x + 1 == player.x && nps_unit.y == player.y) {
					check_player = true;
					damage(player, nps_unit);;
					hit_nps = true;
				}
				if (!check_nps && !check_player) nps_unit.x += 1;
				if (nps_unit.x == width - 1) nps_unit.x = width - 2;
				break;
			}
			case 2: {
				for (Character& nps_check : nps) {
					if (nps_unit.x == nps_check.x && nps_unit.y - 1 == nps_check.y) {
						check_nps = true;
						break;
					}
				}
				if (nps_unit.x == player.x && nps_unit.y - 1 == player.y) {
					check_player = true;
					damage(player, nps_unit);;
					hit_nps = true;
				}
				if (!check_nps && !check_player) nps_unit.y -= 1;
				if (nps_unit.y == 0) nps_unit.y = 1;
				break;
			}
			case 3: {
				for (Character& nps_check : nps) {
					if (nps_unit.x == nps_check.x && nps_unit.y + 1 == nps_check.y) {
						check_nps = true;
						break;
					}
				}
				if (nps_unit.x == player.x && nps_unit.y + 1 == player.y) {
					check_player = true;
					damage(player, nps_unit);;
					hit_nps = true;
				}
				if (!check_nps && !check_player) nps_unit.y += 1;
				if (nps_unit.y == length - 1) nps_unit.y = length - 2;
				break;
			}
		}
	}
}

int main() {
	setup();

	player.x = 10;
	player.y = 10;

	while (status_game) {
		input();
		move_nps();
		status_check();
		draw();
		status_check();
	}

	system("cls");
	std::cout << status_string;
}

#include <vector>
#include <iostream>

// area bildings house S floor rooms type_rooms srooms hroms furnace

struct Room {
	std::string type;
	double room_s = 0;
};

struct Floor {
	double floor_h = 0;
	int num_rooms = 0;
	std::vector<Room> rooms;
};

struct Bilding {
	std::string type;
	bool furnace = false;
	double bildings_s = 0;
	int num_floors = 0;
	std::vector<Floor> floors;
};

struct Plot {
	int area_id = 0;
	double area_s = 0;
	int num_bildings = 1;
	std::vector<Bilding> bildings;
};

int main() {
	int num_plots = 0;
	std::cout << "Enter the number of land plots: ";
	std::cin >> num_plots;
	std::vector<Plot> village(num_plots);
	for (int i = 0; i < num_plots; i++) {
		Plot plot;
		plot.area_id = i + 1;
		std::cout << "Plots id: " << plot.area_id << std::endl;
		std::cout << "| " << "Enter S plots (id " << plot.area_id << "): ";
		std::cin >> plot.area_s;
		std::cout << "| " << "Enter the number of bildings (id " << plot.area_id << "): ";
		std::cin >> plot.num_bildings;
		for (int j = 0; j < num_plots; j++) {
			Bilding bilding;
			std::cout << "| | " << j + 1 << "# Enter type bilding: ";
			std::cin >> bilding.type;
			while (true) {
				std::string answer;
				std::cout << "| | " << "Furnace in bilding (" << bilding.type << ") (yes/no): ";
				std::cin >> answer;
				if (answer == "yes") {
					bilding.furnace = true;
					break;
				} else if (answer == "no") {
					bilding.furnace = false;
					break;
				} else {
					std::cout << "| | " << "Error, repit" << std::endl;
				}
			}
			std::cout << "| | " << "Enter S bilding: (" << bilding.type << ") ";
			std::cin >> bilding.bildings_s;
			std::cout << "| | " << "Enter the number of floors in bilding (" << bilding.type << "): ";
			std::cin >> bilding.num_floors;
			for (int k = 0; k < bilding.num_floors; k++) {
				Floor floor;
				std::cout << "| | | " << "Enter H floor # " << k + 1 << ": ";
				std::cin >> floor.floor_h;
				std::cout << "| | | " << "Enter the number of rooms in floor # " << k + 1 << ": ";
				std::cin >> floor.num_rooms;
				for (int g = 0; g < floor.num_rooms; g++) {
					Room room;
					std::cout << "| | | | " << "Enter type room # " << g + 1 << ": ";
					std::cin >> room.type;
					std::cout << "| | | | " << "Enter S room (" << room.type << "): ";
					std::cin >> room.room_s;
					floor.rooms.push_back(room);
				}
				bilding.floors.push_back(floor);
			}
			plot.bildings.push_back(bilding);
		}
		std::cout << std::endl;
		village.push_back(plot);
	}

	int all_bilding = 0;
	double s_head = 0;
	for (Plot i : village) {
		all_bilding += i.num_bildings;
		for (Bilding j : i.bildings) {
			if (j.furnace) s_head += j.bildings_s * j.num_floors;
		}
	}
	std::cout << std::endl;
	std::cout << "ALL bilding in village = " << all_bilding << std::endl;
	std::cout << "S heated area in village = " << s_head;
}

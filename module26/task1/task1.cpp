#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#pragma warning(disable : 4996)

class Track {
  std::string name{};
  std::tm date{};
  int duration{};

public:
  void init_track(int &num_m) {
    name += "Melody#" + std::to_string(num_m);
    duration = rand() % 100 + 100;

    std::time_t a = std::time(nullptr);
    a -= duration * 100000;
    date = *std::localtime(&a);
  }

  void info_track() {
    std::cout << name << "  Duration: " << duration
              << " Date create: " << std::put_time(&date, "%d.%m.%y")
              << std::endl;
  }
};

class Player {
  int all = 10;
  int num = 0;
  int tmp = -1;
  std::vector<Track> disk{};
  bool pause = false;
  bool play = false;

public:
  void init_disk() {
    for (int i = 0; i < all; i++) {
      Track tr;
      int id = i + 1;
      tr.init_track(id);
      disk.push_back(tr);
    }
  }

  void info_disk() {
    for (int i = 0; i < all; i++) {
      std::cout << i + 1 << ". ";
      disk[i].info_track();
    }
  }

  void play_track() {
    do {
      std::cout << " | Enter number track: ";
      std::cin >> num;
      if (num < 1 || num > all)
        std::cout << " | Error" << std::endl;
    } while (num < 1 || num > all);

    if (tmp != num) {
      tmp = num;
      std::cout << " | PLAY" << std::endl << " | ";
      disk[num-1].info_track();
      play = true;
    }
  }

  void pause_track() {
    if (!pause && play) {
      std::cout << " | PAUSE " << std::endl;
      pause = false;
    }
  }

  void next_track() {
    std::srand(std::time(nullptr));
    do {
      num = rand() % all;
    } while (num == tmp);
    tmp = num;
    std::cout << " | PLAY" << std::endl << " | ";
    disk[num].info_track();
    play = true;
  }

  void stop_track() {
    if (play) {
      std::cout << " | STOP " << std::endl;
      play = false;
      tmp = -1;
    }
  }
};

int main() {
  std::string com;
  Player* player = new Player;

  player->init_disk();
  std::cout << "Disk \"New album\"" << std::endl;
  player->info_disk();

  while (true) {
    std::cout << "Enter command: ";
    std::cin >> com;
    if (com == "play") {
      player->play_track();
    } else if (com == "pause") {
      player->pause_track();
    } else if (com == "next") {
      player->next_track();
    } else if (com == "stop") {
      player->stop_track();
    } else if (com == "exit") {
      std::cout << "EXIT";
      break;
    } else {
      std::cout << "Error,command" << std::endl;
    }
  }

  delete player;
  player = nullptr;
}
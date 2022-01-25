#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <mutex>

std::mutex station;

void trip(std::pair<std::string, int>* train) {
  std::this_thread::sleep_for(std::chrono::seconds(train->second));

  if (station.try_lock()) {
    station.unlock();
  } else {
  std::cout << std::endl << train->first << " is awaiting command of the station." << std::endl;
  }

  station.lock();
  std::cout << "Arrival of " << train->first << std::endl;
  std::string com;
  do {
    std::cout << "depart ???: ";
    std::cin >> com;
  } while (com != "depart");

  std::cout << "Departure of " << train->first << std::endl;
  station.unlock();
}

int main() {
  std::string tr[] = {"Train A", "Train B", "Train C"};
  std::vector<std::pair<std::string, int>> trains(3);

  for (int i = 0; i < 3; i++) {
    std::cout << tr[i] << " Enter time: ";
    trains[i].first = tr[i];
    std::cin >> trains[i].second;
  }

  std::vector<std::thread> trainway(3);

  for (int i = 0; i < 3; i++) {
    trainway[i] = std::thread(trip, &trains[i]);
  }

  for (int i = 0; i < 3; i++) {
    trainway[i].join();
  }
}

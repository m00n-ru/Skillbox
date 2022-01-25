#include <iostream>
#include <chrono>
#include <mutex>
#include <thread>
#include <vector>

std::mutex mtx;

void swim(std::pair<std::string, double>* swimmer, std::vector<std::pair<std::string, double>>* ratings) {
  double distance = 100.0;
  do {
    distance -= swimmer->second;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    mtx.lock();
    if (distance <= 0) {
      distance = 0.0;
      ratings->push_back(*swimmer);
    }
    std::cout << swimmer->first << ": dist= " << 100.0 - distance << std::endl;
    mtx.unlock();
  } while (distance > 0);
}

int main() {
  const int maxSwimmer = 2;
  std::vector<std::pair<std::string, double>> race;
  std::vector<std::pair<std::string, double>> ratings;

  for (int i = 0; i < maxSwimmer; i++) {
    std::pair<std::string, double> swimmer;
    std::cout << i + 1 <<" Enter name: ";
    std::cin >> swimmer.first;
    std::cout << i + 1 << " Enter speed: ";
    std::cin >> swimmer.second;
    race.push_back(swimmer);
  }

  std::vector<std::thread> threads(maxSwimmer);
  for (int i = 0; i < maxSwimmer; i++) {
    threads[i] = std::thread(swim, &race[i], &ratings);
  }

  for (int i = 0; i < maxSwimmer; i++) {
    threads[i].join();
  }

  std::cout << "\nSwim rating\n";
  for (int i = 0; i < maxSwimmer; i++) {
    std::cout << i + 1 << ratings[i].first << " time: " << 100.0 / ratings[i].second << std::endl;
  }
}
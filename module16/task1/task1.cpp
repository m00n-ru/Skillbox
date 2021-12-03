#include <iostream>
#include <sstream>
#include <string>

int main() {
  float acc = 0.01;
  float speed = 0;
  float d;
  std::stringstream speedText;

  do {
    std::cout << "Enter speed: ";
    std::cin >> d;
		speed += d;

    if (speed + acc > 150) {
      std::cout << "Error, limit speed 150!" << std::endl;
      speed = 150;
    } else if (speed - acc < 0) {
      speed = 0;
    }

    speedText << "Speed: " << std::to_string(speed) << " km/h";
    std::cout << speedText.str() << std::endl;
    speedText.str("");
  } while (speed != 0);
}

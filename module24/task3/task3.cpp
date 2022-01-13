#include <iostream>
#include <ctime>
#include <iomanip>

#pragma warning(disable : 4996)

int main() {

  std::cout << "Enter timer" << std::endl;
  std::time_t min {};
  std::time_t sec {};

  do {
	std::cout << "Enter minutes: ";
	std::cin >> min;
	std::cout << "Enter seconds: ";
	std::cin >> sec;
	if ( min < 0 || min > 59 || sec < 0 || sec > 59 ) {
	  std::cout << "Error input" << std::endl;
	}
  } while ( min < 0 || min > 59 || sec < 0 || sec > 59 );

  std::time_t t_set = std::time(nullptr);
  t_set += min * 60 + sec;

  std::time_t current = std::time(nullptr);
  std::time_t tmp = current;

  while ( t_set != current ) {
	current = std::time(nullptr);
	if ( tmp != current ) {
	  tmp = current;
	  std::time_t timer = t_set - current;
	  std::cout << std::put_time(localtime(&timer), "%M:%S") << std::endl;
	}
  }
  std::cout << "DING! DING! DING!" << std::endl;
}
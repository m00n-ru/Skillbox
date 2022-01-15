#include <iostream>
#include "struct.h"


Coord input_coord() {
  Coord c {};

  std::cout << "Input X coord: ";
  std::cin >> c.x;
  std::cout << "Input Y coord: ";
  std::cin >> c.y;

  return c;
}

void output_coord(Coord& c) {
  std::cout << "X= " << c.x << " Y= " << c.y << std::endl;
}

bool equal_coord(Coord& c) {
  if ( c.x == c.y ) {
	std::cout << "Error, coord equal" << std::endl;
	return false;
  } else {
	return true;
  }
}

bool check_interval(Coord& c, int& a) {
  if ( a >= c.x && a <= c.y || a >= c.y && a <= c.x ) {
	return true;
  } else {
	std::cout << "Error, coord outside the interval" << std::endl;
	return false;
  }
}

bool equal_struct(Coord& a, Coord& b) {
  return ( a.x == b.x && a.y == b.y || a.x == b.y && a.y == b.x );
}
#include "func.h"
#include "struct.h"


int main() {
  Coord coord {};

  std::cout << "Operation START \t" << std::endl;
  scalpel(coord);
  while ( true ) {
	std::string com;
	std::cout << "Enter command: ";
	std::cin >> com;
	if ( com == "hemostat" ) {
	  hemostat(coord);
	} else if ( com == "tweezers" ) {
	  tweezers(coord);
	} else if ( com == "suture" ) {
	  if ( suture(coord) );
	  break;
	} else {
	  std::cout << "Unknown command" << std::endl;
	}
  }
  std::cout << "Operation END" << std::endl;
}
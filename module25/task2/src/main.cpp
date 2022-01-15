#include "header.h"


int main() {
  
  std::string command;

  while (true) {
	std::cout << "Enter the command(sum/save/load/input/display/exit): ";
	std::cin >> command;

	if ( command == "sum" ) {
	  std::cout << compute(read()) << std::endl;
	} else if ( command == "save" ) {
	  save(read());
	} else if ( command == "load" ) {
	  write(load());
	} else if ( command == "input" ) {
	  write(input());
	} else if ( command == "display" ) {
	  display(read());
	} else if ( command == "exit" ) {
	  break;
	} else {
	  std::cout << "Error command" << std::endl;
	  continue;
	}
  }
}
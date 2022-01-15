#include "gpu.h"

void display(const std::vector<int>& ram) {
  if ( ram.empty() ) {
	std::cout << "RAM is empty";
  } else {
	for ( int i : ram ) {
	  std::cout << i << " ";
	}
  }
  std::cout << std::endl;
}


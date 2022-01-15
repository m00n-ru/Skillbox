#include "disk.h"
#include <fstream>
#include <iostream>

void save(const std::vector<int>& vec) {
  std::ofstream file(file_name);
  if ( file.is_open() ) {
	for ( int i : vec ) {
	  file << i << std::endl;
	}
	std::cout << "File save" << std::endl;
	file.close();
  } else {
	std::cout << "File not found!";
  }
}

std::vector<int> load() {
  std::vector<int> vec(8);
  std::ifstream file(file_name);
  if ( file.is_open() ) {
	for ( int i = 0; i < 8; ++i ) {
	  file >> vec[i];
	}
	std::cout << "File load" << std::endl;
	file.close();
  } else {
	std::cout << "File not found!";
  }

  return vec;
}
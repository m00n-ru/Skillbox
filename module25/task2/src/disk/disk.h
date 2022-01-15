#pragma once
#include <string>
#include <vector>

const std::string file_name = "data.txt";

void save(const std::vector<int>&);

std::vector<int> load();
#pragma once

struct Coord {
  int x = 0;
  int y = 0;
};

Coord input_coord();

void output_coord(Coord& c);

bool equal_coord(Coord& c);

bool check_interval(Coord& c, int& a);

bool equal_struct(Coord& a, Coord& b);
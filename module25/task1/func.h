#pragma once

#include <iostream>
#include "struct.h"

//scalpel — принимает на вход две двумерные координаты начала и конца разреза или линии отсечения.При выполнении этой команды в консоль выводится сообщение о том, что был сделан разрез между введёнными координатами.

void scalpel(Coord& coord) {
  std::cout << "SCALPEL. Input coord" << std::endl;
  do {
	coord = input_coord();
  } while ( !equal_coord(coord) );
  std::cout << "Incision: OK  ";
  output_coord(coord);
  std::cout << std::endl;
}

//hemostat — эта команда принимает на вход одну точку, в которой требуется сделать зажим, о чём также сообщает в консоль.

void hemostat(Coord& coord) {
  int a;
  do {
	std::cout << "HEMOSTAT. Input coord: ";
	std::cin >> a;
  } while ( !check_interval(coord, a) );
  std::cout << "HEMOSTAT: OK" << std::endl;
}

//tweezers — пинцет, как и зажим, принимает одну точку для применения.Сообщение об этом выводится в консоль.

void tweezers(Coord& coord) {
  int a;
  do {
	std::cout << "TWEEZERS. Input coord: ";
	std::cin >> a;
  } while ( !check_interval(coord, a) );
  std::cout << "TWEEZERS: OK" << std::endl;
}

//suture — команда хирургической иглы, которая делает шов между двумя указанными точками.

int suture(Coord& coord) {
  std::cout << "SUTURE. Input coord" << std::endl;
  Coord coord_suture;
  do {
    coord_suture = input_coord();
	if ( !equal_struct(coord,coord_suture))
	  std::cout << "The coordinates of the incision should be equal to the seam";
  } while ( !equal_struct(coord, coord_suture) );
  std::cout << "SUTURE: OK  " ;
  output_coord(coord);
  std::cout << std::endl;
  return 0;
}

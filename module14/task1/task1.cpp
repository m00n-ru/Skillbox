﻿#include <iostream>

int main()
{
	const int n = 12; // кол. мест
	const int m = 9; // комплект места
	int table[n][m] = {{1,1,1,1,1,1,1,1,1},
										 {1,1,1,1,1,1,1,1,1},
										 {0,1,1,1,0,1,1,0,1},
										 {0,1,1,1,0,1,1,0,1},
										 {0,1,1,1,0,1,1,0,1},
										 {0,1,1,1,0,1,1,0,1},
										 {0,1,1,1,0,1,1,0,1},
										 {0,1,1,1,0,1,1,0,1},
										 {0,1,1,1,0,1,1,0,1},
										 {0,1,1,1,0,1,1,0,1},
										 {0,1,1,1,0,1,1,0,1},
										 {0,1,1,1,0,1,1,0,1},};
	// {0)vip,1)ложка,2)вилка,3)нож,4)мал.лож,5)1тарел,6)2тарел,7)дес.тарел,8)стул}
	table[4][8] += 1;
	table[9][1] -= 1;

	table[1][1] -= 1;
	table[9][1] += 1;
	table[1][7] -= 1;

	for(int i = 0; i < 12; i++) {
		for(int j = 0; j < 9; j++) {
			std::cout << table[i][j];
		}
		std::cout << std::endl;
	}
}
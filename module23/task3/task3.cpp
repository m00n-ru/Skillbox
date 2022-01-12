#include <iostream>

#define SPRING 1
#define SUMMER 2
#define AUTUMN 3
#define WINTER 4

#define TY SUMMER

int main() {
#if TY == SPRING
	std::cout << "Spring";
#elif TY == SUMMER
	std::cout << "Summer";
#elif TY == AUTUMN
	std::cout << "Autumn";
#elif TY == WINTER
	std::cout << "Winter";
#endif	
}
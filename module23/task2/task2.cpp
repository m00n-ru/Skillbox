#include <iostream>

#define FOR_FUNC(func,arr) for(int i = 0; i < 10; i++){func(arr, i);}

#define COUNT(arr, sum) for(int i : arr) { sum+= i;}\
						std::cout << "All passengers: " <<sum; 

void input(int* a, int i) {
	std::cout << "Input passengers in " << i << " wagon: ";
	std::cin >> a[i];
}

void overflow(int* a, int i) {
	if( a[i] > 20 ) {
		std::cout << i + 1 << " wagon overflow" << std::endl;
	}
}

void free(int* a, int i) {
	if( a[i] < 20 ) {
		std::cout << i + 1 << " wagon free" << std::endl;
	}
}

void count(int* a, int i) {
	if( a[i] < 20 ) {
		std::cout << i + 1 << " wagon free" << std::endl;
	}
}


int main() {
	int wagon[10];
	int sum = 0;
	FOR_FUNC(input, wagon)
	FOR_FUNC(overflow, wagon)
	FOR_FUNC(free, wagon)
	COUNT(wagon, sum)
}
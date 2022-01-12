#include <iostream>

#define DAY(d) (((d) == 1) ? "Mo" : \
		((d) == 2) ? "Tu" : \
		((d) == 3) ? "We" : \
		((d) == 4) ? "Th" : \
		((d) == 5) ? "Fr" : \
		((d) == 6) ? "Su" : \
		((d) == 7) ? "Sa" : "Input error")	

int main() {
	int d;
	std::cin >> d;
	std::cout << DAY(d);
}

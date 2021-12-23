#include <iostream>
#include <cmath>

struct vec {
	double x = 0;
	double y = 0;
};

vec add(vec& a, vec& b) {
	vec c;
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return c;
}

vec subtract(vec& a, vec& b) {
	vec c;
	c.x = a.x - b.x;
	c.y = a.y - b.y;
	return c;
}

vec scale(vec& a, double b) {
	vec c;
	c.x = a.x * b;
	c.y = a.y * b;
	return c;
}

double length(vec& a) {
	return std::sqrt(a.x * a.x + a.y * a.y);
}

vec normalize(vec& a) {
	vec c;
	c.x = a.x / length(a);
	c.y = a.y / length(a);
	return c;
}

int main() {
	int command;

	std::cout << "Enter # commands" << std::endl;
	std::cout << "1. add" << std::endl;
	std::cout << "2. subtract" << std::endl;
	std::cout << "3. scale" << std::endl;
	std::cout << "4. length" << std::endl;
	std::cout << "5. normalize" << std::endl << ">: ";
	std::cin >> command;

	switch (command) {
		case 1: {
			vec a, b;
			std::cout << "Enter cordinate vector 1 x, y: ";
			std::cin >> a.x >> a.y;
			std::cout << "Enter cordinate vector 2 x, y: ";
			std::cin >> b.x >> b.y;
			vec c = add(a, b);
			std::cout << "Answer vector 3 x:" << c.x << " y:" << c.y << std::endl;
			break;
		}
		case 2: {
			vec a, b;
			std::cout << "Enter cordinate vector 1 x, y: ";
			std::cin >> a.x >> a.y;
			std::cout << "Enter cordinate vector 2 x, y: ";
			std::cin >> b.x >> b.y;
			vec c = subtract(a, b);
			std::cout << "Answer vector 3 x:" << c.x << " y:" << c.y << std::endl;
			break;
		}
		case 3: {
			vec a;
			double b;
			std::cout << "Enter cordinate vector 1 x, y: ";
			std::cin >> a.x >> a.y;
			std::cout << "Enter scalar";
			std::cin >> b;
			vec c = scale(a, b);
			std::cout << "Answer vector 2 x:" << c.x << " y:" << c.y << std::endl;
			break;
		}
		case 4: {
			vec a;
			std::cout << "Enter cordinate vector 1 x, y: ";
			std::cin >> a.x >> a.y;
			double c = length(a);
			std::cout << "Answer length: " << c << std::endl;
			break;
		}
		case 5: {
			vec a;
			std::cout << "Enter cordinate vector 1 x, y: ";
			std::cin >> a.x >> a.y;
			vec c = normalize(a);
			std::cout << "Answer vector 2 x:" << c.x << " y:" << c.y << std::endl;
			break;
		}
		default: {
			std::cout << "error";
			break;
		}
	}
}

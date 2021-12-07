#include <iostream>
#include <vector>

void swapvec (std::vector<int> &a, int *b, size_t &sizeArr){
	size_t len = sizeArr <= a.size() ? sizeArr : a.size();
	for(int i =0; i < len; i ++ ){
		int buf = a[i];
		a[i] = b[i];
		b[i] = buf;
	}
}



int main() {
	std::vector<int> a = {1,2,3,4};
	int b[] = {5,6,7,8};
	size_t size = sizeof(b) / sizeof(*b);

	for(int i  : a){
		std::cout << i;
	}
	std::cout << std::endl;

	for(int i : b){
		std::cout << i;
	}
	std::cout << std::endl << "Swap" << std::endl;

	swapvec(a, b, size);

	for(int i  : a){
		std::cout << i;
	}
	std::cout << std::endl;

	for(int i : b){
		std::cout << i;
	}
	std::cout << std::endl;

}
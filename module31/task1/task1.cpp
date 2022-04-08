#include <iostream>

class Toy {
	std::string nameToy;
public:
	Toy() : nameToy("Some toy") {};
	Toy(const std::string name) : nameToy(name) {};
	~Toy() {};
	std::string& get_name() {
		return nameToy;
	}
};

class shared_ptr_toy {
	Toy* pToy;
	int* num;
public:
	shared_ptr_toy();
	shared_ptr_toy(const Toy& t);
	shared_ptr_toy(const shared_ptr_toy& pt);
	shared_ptr_toy& operator=(const shared_ptr_toy& pt);
	~shared_ptr_toy();
};

shared_ptr_toy::shared_ptr_toy() : pToy(nullptr), num(nullptr) {
	std::cout << "--Create empty ptr" << std::endl;
}

shared_ptr_toy::shared_ptr_toy(const Toy& t) : pToy(new Toy(t)), num(new int(1)) {
	std::cout << "--Create ptr: " << pToy->get_name() << " all_ptr = " << *num << std::endl;
}

shared_ptr_toy::shared_ptr_toy(const shared_ptr_toy& pt) {
	pToy = pt.pToy;
	num = pt.num;
	++(*num);
	std::cout << "--Copy ptr: " << pToy->get_name() << " all_ptr = " << *num << std::endl;
}

shared_ptr_toy& shared_ptr_toy::operator=(const shared_ptr_toy& pt) {
	if (this == &pt) {
		return *this;
	}

	if (--(*num) == 0) {
		std::cout << "--Delete ptr oper=: " << pToy->get_name() << " all_ptr = " << *num << std::endl;
		delete num;
		delete pToy;
	}

	if (pt.pToy) {
		pToy = pt.pToy;
		num = pt.num;
		++(*num);
		std::cout << "--Oper= ptr: " << pToy->get_name() << " all_ptr = " << *num << std::endl;
		return *this;
	}

	pToy=nullptr;
	num = nullptr;
	std::cout << "--Oper= nullptr " << std::endl;
	return *this;
}

shared_ptr_toy::~shared_ptr_toy() {
	if (pToy) {
		if (--(*num) == 0) {
			std::cout << "--Delete ptr: " << pToy->get_name() << " all_ptr = " << *num << std::endl;
			delete num;
			delete pToy;
		} else {
			std::cout << "--Delete ptr: " << pToy->get_name() << " all_ptr = " << *num << std::endl;
		}
	} else {
		std::cout << "--Delete nullptr: " << std::endl;
	}
}

shared_ptr_toy make_shared_toy(const Toy& toy) {
	shared_ptr_toy ptr(toy);
	return ptr;
}

shared_ptr_toy make_shared_toy(const std::string& str) {
	Toy toy(str);
	shared_ptr_toy ptr(toy);
	return ptr;
}

int main() {
	Toy toyO("Toy 1");

	std::cout << "1" << std::endl;
	shared_ptr_toy ptr1 = make_shared_toy(toyO);

	std::cout << "2" << std::endl;
	shared_ptr_toy ptr2 = ptr1;

	std::cout << "3" << std::endl;
	shared_ptr_toy ptr3;

	std::cout << "4" << std::endl;
	ptr2 = ptr3;

	std::cout << "5" << std::endl;
	shared_ptr_toy ptr4 = make_shared_toy("Toy 2");

	std::cout << "6" << std::endl;
	ptr1 = ptr4;
	std::cout << "7" << std::endl;

}

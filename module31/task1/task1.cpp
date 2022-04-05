#include <iostream>

class Toy {
	std::string nameToy;
public:
	Toy(const std::string name) : nameToy(name) {};
	Toy() : Toy("Some-toy") {};
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

shared_ptr_toy::shared_ptr_toy() : pToy(new Toy), num(new int(1)) {
	std::cout << "Create ptr: " << pToy->get_name() << " all_ptr = " << *num << std::endl;
}

shared_ptr_toy::shared_ptr_toy(const Toy& t) : pToy(new Toy(t)), num(new int(1)) {
	std::cout << "Create ptr: " << pToy->get_name() << " all_ptr = " << *num << std::endl;
}

shared_ptr_toy::shared_ptr_toy(const shared_ptr_toy& pt) {
	pToy = new Toy(*pt.pToy);
	num = pt.num;
	++(*num);
	std::cout << "Copy ptr: " << pToy->get_name() << " all_ptr = " << *num << std::endl;
}

shared_ptr_toy& shared_ptr_toy::operator=(const shared_ptr_toy& pt) {
	if(this == &pt) {
		return *this;
	}

	if(pToy != nullptr) {
		--(*num);
		std::cout << "Delete ptr: " << pToy->get_name() << " all_ptr = " << *num << std::endl;
		if(*num == 0) {
			delete num;
			num = new int;
		}
		delete pToy;
	}

	pToy = new Toy(*pt.pToy);
	num = pt.num;
	++(*num);
	std::cout << "Copy ptr: " << pToy->get_name() << " all_ptr = " << *num << std::endl;
	return *this;
}

shared_ptr_toy::~shared_ptr_toy() {
	if(*num > 1) {
		--(*num);
		std::cout << "Delete ptr: " << pToy->get_name() << " all_ptr = " << *num << std::endl;
		delete pToy;
		return;
	}
	--(*num);
	std::cout << "Delete ptr: " << pToy->get_name() << " all_ptr = " << *num << std::endl;
	delete pToy;
	delete num;
}

class UserPtr {
	shared_ptr_toy pToy;
public:
	UserPtr(shared_ptr_toy& ptr) : pToy(ptr) {};
	UserPtr& operator=(const UserPtr& ptr) {
		this->pToy = ptr.pToy;
		return *this;
	}
};

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
	Toy toy1;
	std::cout << "Create 2 shared_ptr_toy : " << std::endl;
	shared_ptr_toy ptrToy1 = make_shared_toy(toy1);
	shared_ptr_toy ptrToy2 = make_shared_toy("Toy-Toy");

	std::cout << std::endl;
	std::cout << "Create 5 users shared_ptr_toy : " << std::endl;
	UserPtr	user1a(ptrToy1);
	UserPtr	user2a(ptrToy1);
	UserPtr	user3a(ptrToy1);
	UserPtr	user1b(ptrToy2);
	UserPtr	user2b(ptrToy2);

	std::cout << std::endl;
	std::cout << "Copy shared_ptr_toy : " << std::endl;
	user1b = user1a;
	user2b = user1a;

	std::cout << std::endl;
	std::cout << "End program" << std::endl;
}

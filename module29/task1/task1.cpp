#include <iostream>

class Animal {
  
  const char* type;


public:
  Animal(const char* type) : type(type) {}

  const char* get_type() {
    return type;
  }

  virtual const char* voice(Animal* ptr) = 0;
};

class Dog : public Animal {
public:
  Dog(const char* type) : Animal(type) {}

  const char* voice(Animal* p) {
    if (this->get_type() == p->get_type()) {
      return "Woof";
    } else {
      return "Bark";
    }
  }
};

class Cat : public Animal {
public:
  Cat(const char* type) : Animal(type) {}

  const char* voice(Animal* p) {
    if (this->get_type() == p->get_type()) {
      return "Purr";
    } else {
      return "Meow";
    }
  }
};

void meeting(Animal* p1, Animal* p2) {
  std::cout << p1->get_type() << " + " << p2->get_type()
    << " -> " << p1->voice(p2) << "-" << p2->voice(p1) << std::endl;
}

int main() {
  Animal* pDog = new Dog("Dog");
  Animal* pCat = new Cat("Cat");
  meeting(pDog, pDog);
  meeting(pDog, pCat);
  meeting(pCat, pDog);
  meeting(pCat, pCat);
}

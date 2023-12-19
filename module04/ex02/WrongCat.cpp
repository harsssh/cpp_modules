#include "WrongCat.h"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cerr << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	std::cerr << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat() {
	std::cerr << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
	std::cerr << "WrongCat assignation operator called" << std::endl;
	if (this != &other) {
		WrongAnimal::operator=(other);
	}
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "Meoooooooow!" << std::endl;
}

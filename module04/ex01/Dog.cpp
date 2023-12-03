#include "Dog.h"
#include <iostream>

Dog::Dog() : Animal("Dog") {
	std::cerr << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cerr << "Dog copy constructor called" << std::endl;
	*this = other;
}

Dog::~Dog() {
	std::cerr << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
	std::cerr << "Dog assignation operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof!" << std::endl;
}

#include "Cat.h"
#include <iostream>

Cat::Cat() : Animal("Cat") {
	std::cerr << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
	std::cerr << "Cat copy constructor called" << std::endl;
	*this = other;
}

Cat::~Cat() {
	std::cerr << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
	std::cerr << "Cat assignation operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}

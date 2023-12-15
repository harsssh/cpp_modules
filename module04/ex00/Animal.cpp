#include "Animal.h"
#include <iostream>

Animal::Animal() : type_("Animal") {
	std::cerr << "Animal default constructor called" << std::endl;
}

Animal::Animal(const std::string &type) : type_(type) {
	std::cerr << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &animal) {
	std::cerr << "Animal copy constructor called" << std::endl;
	*this = animal;
}

Animal::~Animal() {
	std::cerr << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &animal) {
	std::cerr << "Animal copy assignment operator called" << std::endl;
	if (this != &animal) {
		this->type_ = animal.type_;
	}
	return *this;
}

std::string Animal::getType() const {
	return this->type_;
}

void Animal::makeSound() const {
	std::cout << this->type_ << " makes sound" << std::endl;
}

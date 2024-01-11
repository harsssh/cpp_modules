#include "WrongAnimal.h"
#include <iostream>

WrongAnimal::WrongAnimal() : type_("WrongAnimal") {
	std::cerr << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type) : type_(type) {
	std::cerr << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &animal) {
	std::cerr << "WrongAnimal copy constructor called" << std::endl;
	*this = animal;
}

WrongAnimal::~WrongAnimal() {
	std::cerr << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &animal) {
	std::cerr << "WrongAnimal copy assignment operator called" << std::endl;
	if (this != &animal) {
		this->type_ = animal.type_;
	}
	return *this;
}

const std::string &WrongAnimal::getType() const {
	return this->type_;
}

void WrongAnimal::makeSound() const {
	std::cout << this->type_ << " makes sound" << std::endl;
}

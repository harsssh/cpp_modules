#include "AbstractAnimal.h"
#include <iostream>

AbstractAnimal::AbstractAnimal() : type_("AbstractAnimal") {
	std::cerr << "AbstractAnimal default constructor called" << std::endl;
}

AbstractAnimal::AbstractAnimal(std::string type) : type_(type) {
	std::cerr << "AbstractAnimal constructor called" << std::endl;
}

AbstractAnimal::AbstractAnimal(const AbstractAnimal &animal) {
	std::cerr << "AbstractAnimal copy constructor called" << std::endl;
	*this = animal;
}

AbstractAnimal::~AbstractAnimal() {
	std::cerr << "AbstractAnimal destructor called" << std::endl;
}

AbstractAnimal &AbstractAnimal::operator=(const AbstractAnimal &animal) {
	std::cerr << "AbstractAnimal copy assignment operator called" << std::endl;
	if (this != &animal) {
		this->type_ = animal.type_;
	}
	return *this;
}

std::string AbstractAnimal::getType() const {
	return this->type_;
}

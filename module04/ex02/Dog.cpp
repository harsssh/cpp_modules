#include "Dog.h"
#include <iostream>

Dog::Dog() : AbstractAnimal("Dog") {
	std::cerr << "Dog default constructor called" << std::endl;
	this->brain_ = new Brain();
}

Dog::Dog(const Dog &other) : AbstractAnimal(other) {
	std::cerr << "Dog copy constructor called" << std::endl;
	*this = other;
}

Dog::~Dog() {
	std::cerr << "Dog destructor called" << std::endl;
	delete this->brain_;
}

Dog &Dog::operator=(const Dog &other) {
	std::cerr << "Dog assignation operator called" << std::endl;
	if (this != &other) {
		AbstractAnimal::operator=(other);
		// brain_ is not NULL
		// use Brain's assignation operator to copy the ideas
		*brain_ = *other.brain_;
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof!" << std::endl;
}

void Dog::setIdea(size_t index, const std::string &idea) {
	this->brain_->setIdea(index, idea);
}

const std::string &Dog::getIdea(size_t index) const {
	return this->brain_->getIdea(index);
}

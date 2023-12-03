#include "Cat.h"
#include <iostream>

Cat::Cat() : Animal("Cat") {
	std::cerr << "Cat default constructor called" << std::endl;
	this->brain_ = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other) {
	std::cerr << "Cat copy constructor called" << std::endl;
	*this = other;
}

Cat::~Cat() {
	std::cerr << "Cat destructor called" << std::endl;
	delete this->brain_;
}

Cat &Cat::operator=(const Cat &other) {
	std::cerr << "Cat assignation operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		// brain_ is not NULL
		// use Brain's assignation operator to copy the ideas
		*brain_ = *other.brain_;
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}

void Cat::setIdea(size_t index, const std::string &idea) {
	this->brain_->setIdea(index, idea);
}

const std::string &Cat::getIdea(size_t index) const {
	return this->brain_->getIdea(index);
}

#include "Brain.h"
#include <iostream>

Brain::Brain() {
	std::cerr << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &other) {
	std::cerr << "Brain copy constructor called" << std::endl;
	*this = other;
}

Brain::~Brain() {
	std::cerr << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &other) {
	std::cerr << "Brain assignation operator called" << std::endl;
	if (this != &other) {
		for (size_t i = 0; i < Brain::maxIdeas; i++) {
			this->ideas_[i] = other.ideas_[i];
		}
	}
	return *this;
}

void Brain::setIdea(size_t index, const std::string &idea) {
	if (index >= Brain::maxIdeas) {
		throw std::out_of_range("Brain index is out of range");
	}
	this->ideas_[index] = idea;
}

const std::string &Brain::getIdea(size_t index) const {
	if (index >= Brain::maxIdeas) {
		throw std::out_of_range("Brain index is out of range");
	}
	return this->ideas_[index];
}

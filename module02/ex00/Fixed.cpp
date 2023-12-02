#include "Fixed.h"
#include <iostream>

Fixed::Fixed(): raw(0) {
	std::cerr << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) : raw(0) {
	std::cerr << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::~Fixed() {
	std::cerr << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
	std::cerr << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->raw = fixed.getRawBits();
	return *this;
}

int Fixed::getRawBits() const {
	std::cerr << "getRawBits member function called" << std::endl;
	return this->raw;
}

void Fixed::setRawBits(const int r) {
	std::cerr << "setRawBits member function called" << std::endl;
	this->raw = r;
}

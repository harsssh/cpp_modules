#include "Fixed.h"
#include <iostream>

Fixed::Fixed(): raw(0) {
	std::cerr << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) {
	std::cerr << "Int constructor called" << std::endl;
	// do not use shift operator on negative value (undefined behavior)
	this->raw = n * (1 << Fixed::fractionalBits);
}

Fixed::Fixed(const float f) {
	std::cerr << "Float constructor called" << std::endl;
	this->raw = (int)roundf(f * (1 << Fixed::fractionalBits));
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

float Fixed::toFloat() const {
	return (float)this->raw / (1 << Fixed::fractionalBits);
}

int Fixed::toInt() const {
	// do not use shift operator on negative value (undefined behavior)
	return this->raw / (1 << Fixed::fractionalBits);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
	os << fixed.toFloat();
	return os;
}

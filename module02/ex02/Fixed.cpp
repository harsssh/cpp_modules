#include "Fixed.h"
#include <iostream>
#include <cmath>

Fixed::Fixed() : raw_(0) {
	std::cerr << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) {
	std::cerr << "Int constructor called" << std::endl;
	// do not use shift operator on negative value (undefined behavior)
	this->raw_ = n * (1 << Fixed::fractionalBits_);
}

Fixed::Fixed(const float f) {
	std::cerr << "Float constructor called" << std::endl;
	this->raw_ = (int) std::roundf(f * (1 << Fixed::fractionalBits_));
}

Fixed::Fixed(const Fixed &fixed) : raw_(0) {
	std::cerr << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::~Fixed() {
	std::cerr << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
	std::cerr << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->raw_ = fixed.getRawBits();
	return *this;
}

int Fixed::getRawBits() const {
	std::cerr << "getRawBits member function called" << std::endl;
	return this->raw_;
}

void Fixed::setRawBits(const int r) {
	std::cerr << "setRawBits member function called" << std::endl;
	this->raw_ = r;
}

float Fixed::toFloat() const {
	return (float) this->raw_ / (1 << Fixed::fractionalBits_);
}

int Fixed::toInt() const {
	// do not use shift operator on negative value (undefined behavior)
	return this->raw_ / (1 << Fixed::fractionalBits_);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
	os << fixed.toFloat();
	return os;
}

bool Fixed::operator==(const Fixed &rhs) const {
	return this->getRawBits() == rhs.getRawBits();
}

bool Fixed::operator!=(const Fixed &rhs) const {
	return !(*this == rhs);
}

bool Fixed::operator<(const Fixed &rhs) const {
	return this->getRawBits() < rhs.getRawBits();
}

bool Fixed::operator<=(const Fixed &rhs) const {
	return !(*this > rhs);
}

bool Fixed::operator>(const Fixed &rhs) const {
	return this->getRawBits() > rhs.getRawBits();
}

bool Fixed::operator>=(const Fixed &rhs) const {
	return !(*this < rhs);
}

Fixed Fixed::operator+(const Fixed &rhs) const {
	Fixed result;
	result.setRawBits(this->getRawBits() + rhs.getRawBits());
	return result;
}

Fixed Fixed::operator-(const Fixed &rhs) const {
	Fixed result;
	result.setRawBits(this->getRawBits() - rhs.getRawBits());
	return result;
}

Fixed Fixed::operator*(const Fixed &rhs) const {
	Fixed result;
	int product = this->getRawBits() * rhs.getRawBits();
	result.setRawBits(product / (1 << Fixed::fractionalBits_));
	return result;
}

Fixed Fixed::operator/(const Fixed &rhs) const {
	Fixed result;
	int shifted = this->getRawBits() * (1 << Fixed::fractionalBits_);
	result.setRawBits(shifted / rhs.getRawBits());
	return result;
}

// pre-increment
Fixed &Fixed::operator++() {
	this->raw_++;
	return *this;
}

// post-increment
Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	operator++();
	return tmp;
}

// pre-decrement
Fixed &Fixed::operator--() {
	this->raw_--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	operator--();
	return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	if (a <= b)
		return a;
	return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	if (a <= b)
		return a;
	return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	if (a >= b)
		return a;
	return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	if (a >= b)
		return a;
	return b;
}

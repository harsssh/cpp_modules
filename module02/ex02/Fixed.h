#ifndef CPP_MODULES_FIXED_H
#define CPP_MODULES_FIXED_H

#include <iostream>

class Fixed {
private:
	int raw_;
	static const int fractionalBits_ = 8;

public:
	Fixed();

	Fixed(int n);

	Fixed(float f);

	Fixed(const Fixed &fixed);

	~Fixed();

	Fixed &operator=(const Fixed &fixed);

	int getRawBits() const;

	void setRawBits(int raw);

	float toFloat() const;

	int toInt() const;

	// comparison operators
	bool operator==(const Fixed &rhs) const;

	bool operator!=(const Fixed &rhs) const;

	bool operator<(const Fixed &rhs) const;

	bool operator<=(const Fixed &rhs) const;

	bool operator>(const Fixed &rhs) const;

	bool operator>=(const Fixed &rhs) const;

	// arithmetic operators
	Fixed operator+(const Fixed &rhs) const;

	Fixed operator-(const Fixed &rhs) const;

	Fixed operator*(const Fixed &rhs) const;

	Fixed operator/(const Fixed &rhs) const;

	// increment and decrement operators
	Fixed &operator++();

	Fixed operator++(int);

	Fixed &operator--();

	Fixed operator--(int);

	static Fixed &min(Fixed &a, Fixed &b);

	static const Fixed &min(const Fixed &a, const Fixed &b);

	static Fixed &max(Fixed &a, Fixed &b);

	static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif //CPP_MODULES_FIXED_H

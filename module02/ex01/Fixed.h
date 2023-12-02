#ifndef CPP_MODULES_FIXED_H
#define CPP_MODULES_FIXED_H

#include <iostream>

class Fixed {
private:
	int raw;
	static const int fractionalBits = 8;

public:
	Fixed();

	Fixed(int n);

	Fixed(float f);

	Fixed(const Fixed &fixed);

	~Fixed();

	Fixed &operator=(const Fixed &fixed);

	int getRawBits() const;

	void setRawBits(int r);

	float toFloat() const;

	int toInt() const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif //CPP_MODULES_FIXED_H

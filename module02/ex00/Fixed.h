#ifndef CPP_MODULES_FIXED_H
#define CPP_MODULES_FIXED_H


class Fixed {
private:
	int raw;
	static const int fractionalBits = 8;

public:
	Fixed();

	Fixed(const Fixed &fixed);

	~Fixed();

	Fixed &operator=(const Fixed &fixed);

	int getRawBits() const;

	void setRawBits(int r);
};


#endif //CPP_MODULES_FIXED_H

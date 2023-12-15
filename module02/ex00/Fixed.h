#ifndef CPP_MODULES_FIXED_H
#define CPP_MODULES_FIXED_H


class Fixed {
private:
	int raw_;
	static const int fractionalBits_ = 8;

public:
	Fixed();

	Fixed(const Fixed &fixed);

	~Fixed();

	Fixed &operator=(const Fixed &fixed);

	int getRawBits() const;

	void setRawBits(int raw);
};


#endif //CPP_MODULES_FIXED_H

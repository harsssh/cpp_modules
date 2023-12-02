#include "Fixed.h"
#include <iostream>

int main() {
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));
	Fixed c;

	std::cout << "[increment/decrement]" << std::endl;
	std::cout << "a\t" << a << std::endl;
	std::cout << "++a\t" << ++a << std::endl;
	std::cout << "a\t" << a << std::endl;
	std::cout << "a++\t" << a++ << std::endl;
	std::cout << "a\t" << a << std::endl;

	std::cout << "c\t" << c << std::endl;
	std::cout << "--c\t" << --c << std::endl;
	std::cout << "c\t" << c << std::endl;
	std::cout << "c--\t" << c-- << std::endl;
	std::cout << "c\t" << c << std::endl;

	std::cout << "[min/max]" << std::endl;
	std::cout << "a=" << a << ", b=" << b << std::endl;
	std::cout << "max(a, b)\t" << Fixed::max(a, b) << std::endl;
	std::cout << "min(a, b)\t" << Fixed::min(a, b) << std::endl;

	std::cout << "[arithmetics]" << std::endl;
	std::cout << "Fixed(2) + Fixed(3)\t" << Fixed(2) + Fixed(3) << std::endl;
	std::cout << "Fixed(2) - Fixed(3)\t" << Fixed(2) - Fixed(3) << std::endl;
	std::cout << "Fixed(2) * Fixed(3)\t" << Fixed(2) * Fixed(3) << std::endl;
	std::cout << "Fixed(3) / Fixed(2)\t" << Fixed(3) / Fixed(2) << std::endl;

	std::cout << "[comparison]" << std::endl;
	std::cout << "Fixed(2) < Fixed(3)\t" << (Fixed(2) < Fixed(3)) << std::endl;
	std::cout << "Fixed(3) > Fixed(2)\t" << (Fixed(3) > Fixed(2)) << std::endl;
	std::cout << "Fixed(2) <= Fixed(3)\t" << (Fixed(2) <= Fixed(3)) << std::endl;
	std::cout << "Fixed(2) <= Fixed(2)\t" << (Fixed(2) <= Fixed(2)) << std::endl;
	std::cout << "Fixed(3) >= Fixed(2)\t" << (Fixed(3) >= Fixed(2)) << std::endl;
	std::cout << "Fixed(2) >= Fixed(2)\t" << (Fixed(2) >= Fixed(2)) << std::endl;
	std::cout << "Fixed(2) == Fixed(2)\t" << (Fixed(2) == Fixed(2)) << std::endl;
	std::cout << "Fixed(2) != Fixed(3)\t" << (Fixed(2) != Fixed(3)) << std::endl;

	std::cout << "Fixed(3) < Fixed(2)\t" << (Fixed(3) < Fixed(2)) << std::endl;
	std::cout << "Fixed(2) > Fixed(3)\t" << (Fixed(2) > Fixed(3)) << std::endl;
	std::cout << "Fixed(3) <= Fixed(2)\t" << (Fixed(3) <= Fixed(2)) << std::endl;
	std::cout << "Fixed(2) >= Fixed(3)\t" << (Fixed(2) >= Fixed(3)) << std::endl;
	std::cout << "Fixed(2) == Fixed(3)\t" << (Fixed(2) == Fixed(3)) << std::endl;
	std::cout << "Fixed(2) != Fixed(2)\t" << (Fixed(2) != Fixed(2)) << std::endl;
}

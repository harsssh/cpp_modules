#ifndef CPP_MODULES_WRONG_CAT_H
#define CPP_MODULES_WRONG_CAT_H

#include "WrongAnimal.h"

class WrongCat : public WrongAnimal {
public:
	WrongCat();

	WrongCat(const WrongCat &other);

	~WrongCat();

	WrongCat &operator=(const WrongCat &other);

	void makeSound() const;
};

#endif //CPP_MODULES_WRONG_CAT_H

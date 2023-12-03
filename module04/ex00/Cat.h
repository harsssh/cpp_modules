#ifndef CPP_MODULES_CAT_H
#define CPP_MODULES_CAT_H

#include "Animal.h"

class Cat : public Animal {
public:
	Cat();

	Cat(const Cat &other);

	virtual ~Cat();

	Cat &operator=(const Cat &other);

	virtual void makeSound() const;
};

#endif //CPP_MODULES_CAT_H

#ifndef CPP_MODULES_ANIMAL_H
#define CPP_MODULES_ANIMAL_H

#include <string>

class Animal {
protected:
	std::string type_;

public:
	Animal();

	Animal(const std::string &type);

	Animal(const Animal &animal);

	virtual ~Animal();

	Animal &operator=(const Animal &animal);

	const std::string & getType() const;

	virtual void makeSound() const;
};

#endif //CPP_MODULES_ANIMAL_H

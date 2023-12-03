#ifndef CPP_MODULES_ANIMAL_H
#define CPP_MODULES_ANIMAL_H

#include <string>

class Animal {
protected:
	std::string type_;

public:
	Animal();

	Animal(std::string type);

	Animal(const Animal &animal);

	virtual ~Animal();

	Animal &operator=(const Animal &animal);

	std::string getType() const;

	virtual void makeSound() const;
};

#endif //CPP_MODULES_ANIMAL_H
#ifndef CPP_MODULES_WRONG_ANIMAL_H
#define CPP_MODULES_WRONG_ANIMAL_H

#include <string>

class WrongAnimal {
protected:
	std::string type_;

public:
	WrongAnimal();

	WrongAnimal(std::string type);

	WrongAnimal(const WrongAnimal &animal);

	~WrongAnimal();

	WrongAnimal &operator=(const WrongAnimal &animal);

	std::string getType() const;

	void makeSound() const;
};

#endif //CPP_MODULES_WRONG_ANIMAL_H

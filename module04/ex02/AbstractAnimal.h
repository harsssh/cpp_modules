#ifndef CPP_MODULES_ABSTRACTANIMAL_H
#define CPP_MODULES_ABSTRACTANIMAL_H

#include <string>

class AbstractAnimal {
protected:
	std::string type_;

public:
	AbstractAnimal();

	AbstractAnimal(std::string type);

	AbstractAnimal(const AbstractAnimal &animal);

	virtual ~AbstractAnimal();

	AbstractAnimal &operator=(const AbstractAnimal &animal);

	std::string getType() const;

	virtual void makeSound() const = 0;
};

#endif //CPP_MODULES_ABSTRACTANIMAL_H

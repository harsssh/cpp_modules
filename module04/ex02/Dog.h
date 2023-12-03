#ifndef CPP_MODULES_DOG_H
#define CPP_MODULES_DOG_H

#include "AbstractAnimal.h"
#include "Brain.h"

class Dog : public AbstractAnimal {
private:
	Brain *brain_;

public:
	Dog();

	Dog(const Dog &other);

	virtual ~Dog();

	Dog &operator=(const Dog &other);

	virtual void makeSound() const;

	void setIdea(size_t index, const std::string &idea);

	const std::string &getIdea(size_t index) const;
};

#endif //CPP_MODULES_DOG_H

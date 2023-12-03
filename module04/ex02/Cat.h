#ifndef CPP_MODULES_CAT_H
#define CPP_MODULES_CAT_H

#include "AbstractAnimal.h"
#include "Brain.h"

class Cat : public AbstractAnimal {
private:
	Brain *brain_;

public:
	Cat();

	Cat(const Cat &other);

	virtual ~Cat();

	Cat &operator=(const Cat &other);

	virtual void makeSound() const;

	void setIdea(size_t index, const std::string &idea);

	const std::string &getIdea(size_t index) const;
};

#endif //CPP_MODULES_CAT_H

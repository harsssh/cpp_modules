#include <iostream>
#include "Animal.h"
#include "Cat.h"
#include "Dog.h"
#include "WrongAnimal.h"
#include "WrongCat.h"

void testNormal() {
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << "Dog.getType()\t" << j->getType() << std::endl;
	std::cout << "Cat.getType()\t" << i->getType() << std::endl;

	std::cout << "Dog.makeSound()\t";
	j->makeSound();

	std::cout << "Cat.makeSound()\t";
	i->makeSound();

	std::cout << "Animal.makeSound()\t";
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
}

void testWrong() {
	const WrongAnimal *meta = new WrongAnimal();
	const WrongAnimal *i = new WrongCat();

	std::cout << "WrongCat.getType()\t" << i->getType() << std::endl;

	std::cout << "WrongCat.makeSound()\t";
	i->makeSound();	// WrongCat's makeSound() is not called

	std::cout << "WrongAnimal.makeSound()\t";
	meta->makeSound();

	delete meta;
	delete i;	// WrongCat's destructor is not called
}

int main() {
	std::cout << "[Normal test]" << std::endl;
	testNormal();

	std::cout << std::endl;

	std::cout << "[Wrong test]" << std::endl;
	testWrong();
}

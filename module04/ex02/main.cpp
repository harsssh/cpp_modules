#include <iostream>
#include "Cat.h"
#include "Dog.h"

int main() {
//	AbstractAnimal cannotInstantiate;
	Dog dog;
	Cat cat;

	std::cout << "Dog.getType(): " << dog.getType() << std::endl;
	std::cout << "Cat.getType(): " << cat.getType() << std::endl;

	std::cout << std::endl;

	std::cout << "Dog.makeSound(): ";
	dog.makeSound();
	std::cout << "Cat.makeSound(): ";
	cat.makeSound();

	std::cout << std::endl;

	dog.setIdea(0, "Dog idea 0");
	cat.setIdea(0, "Cat idea 0");
	std::cout << "Dog.getIdea(0): " << dog.getIdea(0) << std::endl;
	std::cout << "Cat.getIdea(0): " << cat.getIdea(0) << std::endl;
}
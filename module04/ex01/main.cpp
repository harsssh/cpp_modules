#include <iostream>
#include "Animal.h"
#include "Cat.h"
#include "Dog.h"

// appropriate destructors must be called in expected order
void runAnimalArrayTest() {
	const size_t animalCount = 4;
	Animal *animals[animalCount];
	for (size_t i = 0; i < animalCount / 2; i++)
		animals[i] = new Dog();
	for (size_t i = animalCount / 2; i < animalCount; i++)
		animals[i] = new Cat();

	for (size_t i = 0; i < animalCount; i++)
		delete animals[i];
}

// Brain must be copied deeply
void runDeepCopyTest() {
	Dog a1;
	a1.setIdea(0, "idea1");

	std::cout << "a1 idea[0]: " << a1.getIdea(0) << std::endl;
	std::cout << "a1 idea[1]: " << a1.getIdea(1) << std::endl;

	Dog a2;
	a2 = a1;
	a2.setIdea(0, "IDEA1");
	a2.setIdea(1, "IDEA2");

	std::cout << "copied a1 to a2" << std::endl;

	std::cout << "a1 idea[0]: " << a1.getIdea(0) << std::endl;
	std::cout << "a1 idea[1]: " << a1.getIdea(1) << std::endl;
	std::cout << "a2 idea[0]: " << a2.getIdea(0) << std::endl;
	std::cout << "a2 idea[1]: " << a2.getIdea(1) << std::endl;
}

int main() {
	std::cout << "[Animal array test]" << std::endl;
	runAnimalArrayTest();

	std::cout << std::endl;
	std::cout << "[Deep copy test]" << std::endl;
	runDeepCopyTest();
}

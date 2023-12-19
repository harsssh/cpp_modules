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

void copyTest() {
	Dog dog;
	dog.setIdea(0, "dog");
	{
		Dog tmp = dog;
		tmp.setIdea(0, "tmp");
		std::cout << "tmp idea[0]: " << tmp.getIdea(0) << std::endl;
	}
	// dog's brain must not be deleted
	// dog's brain must not be overwritten
	std::cout << "dog idea[0]: " << dog.getIdea(0) << std::endl;
}

int main() {
	std::cout << "[Copy test]" << std::endl;
	copyTest();

	std::cout << std::endl << "[Animal array test]" << std::endl;
	runAnimalArrayTest();

	std::cout << std::endl << "[Deep copy test]" << std::endl;
	runDeepCopyTest();
}

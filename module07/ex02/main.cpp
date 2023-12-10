#include <iostream>
#include "Array.h"

template<typename T>
void printArray(Array<T> &array) {
	std::cout << "[";
	for (unsigned int i = 0; i < array.size(); i++) {
		std::cout << array[i];
		if (i < array.size() - 1)
			std::cout << ", ";
	}
	std::cout << "]" << std::endl;
}

int main() {
	std::cout << "**empty**" << std::endl;
	Array<int> empty;
	std::cout << "empty.size() = " << empty.size() << std::endl;
	try {
		int elem = empty[0];
		std::cout << "empty[0] = " << elem << std::endl;
	} catch (std::exception &e) {
		std::cout << "empty[0] = " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "**string array**" << std::endl;
	Array<std::string> strings(3);
	std::cout << "strings.size() = " << strings.size() << std::endl;
	strings[0] = "Hello";
	strings[1] = "World";
	strings[2] = "!";
	std::cout << "strings = ";
	printArray(strings);

	std::cout << std::endl;
	std::cout << "**copy**" << std::endl;
	Array<std::string> copy(strings);
	std::cout << "copy.size() = " << copy.size() << std::endl;
	std::cout << "copy = ";
	printArray(copy);
	copy[0] = "Goodbye";
	std::cout << "copy = ";
	printArray(copy);
	std::cout << "strings = ";
	printArray(strings);

	std::cout << std::endl;
	std::cout << "**assign**" << std::endl;
	strings = copy;
	std::cout << "strings = ";
	printArray(strings);
}

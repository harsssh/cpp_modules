#include <iostream>
#include "iter.h"

void printInt(const int &i) {
	std::cout << i << std::endl;
}

void printChar(const char &c) {
	std::cout << c << std::endl;
}

int main() {
	int intArray[] = {1, 2, 3, 4, 5};
	char charArray[] = {'a', 'b', 'c', 'd', 'e'};

	iter(intArray, 5, printInt);
	iter(charArray, 5, printChar);
}

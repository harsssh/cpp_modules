#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.h"
#include "A.h"
#include "B.h"
#include "C.h"

Base *generate() {
	int i = rand() % 3;
	if (i == 0) {
		std::cout << "A generated" << std::endl;
		return new A();
	} else if (i == 1) {
		std::cout << "B generated" << std::endl;
		return new B();
	} else {
		std::cout << "C generated" << std::endl;
		return new C();
	}
}

void identify(Base *p) {
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "C" << std::endl;
}

void identify(Base &p) {
	try {
		A &a = dynamic_cast<A &>(p);
		(void) a;
		std::cout << "A" << std::endl;
		return;
	} catch (std::exception &e) {}

	try {
		B &b = dynamic_cast<B &>(p);
		(void) b;
		std::cout << "B" << std::endl;
		return;
	} catch (std::exception &e) {}

	try {
		C &c = dynamic_cast<C &>(p);
		(void) c;
		std::cout << "C" << std::endl;
		return;
	} catch (std::exception &e) {}
}

int main() {
	std::srand(std::time(NULL));
	Base *p = generate();
	std::cout << "identify by pointer: ";
	identify(p);
	std::cout << "identify by reference: ";
	identify(*p);
}

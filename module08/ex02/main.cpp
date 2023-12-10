#include <iostream>
#include "MutantStack.h"

void testNormal() {
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
}

void testIterator() {
	MutantStack<int> mstack;

	for (int i = 0; i < 10; i++)
		mstack.push(i);

	MutantStack<int>::iterator it = std::find(mstack.begin(), mstack.end(), 5);
	if (it != mstack.end())
		std::cout << "found: " << *it << std::endl;
	else
		std::cout << "not found" << std::endl;

	it = std::find(mstack.begin(), mstack.end(), 42);
	if (it != mstack.end())
		std::cout << "found: " << *it << std::endl;
	else
		std::cout << "not found" << std::endl;
}

int main() {
	std::cout << "[Test 1]" << std::endl;
	testNormal();

	std::cout << std::endl << "[Test 2]" << std::endl;
	testIterator();
}

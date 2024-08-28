#include <iostream>
#include <vector>
#include <climits>
#include "Span.h"

void testNormal() {
	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "longest span: " << sp.longestSpan() << std::endl;
}

void testException() {
	Span sp = Span(5);

	try {
		sp.shortestSpan();
	} catch (std::exception &e) {
		std::cout << "shortest span: " << e.what() << std::endl;
	}
	try {
		sp.longestSpan();
	} catch (std::exception &e) {
		std::cout << "longest span: " << e.what() << std::endl;
	}

	std::vector<int> vec(10, 1);
	try {
		sp.addNumber(vec.begin(), vec.end());
	} catch (std::exception &e) {
		std::cout << "addNumber: " << e.what() << std::endl;
	}
}

void testSpanMax() {
	Span sp = Span(2);

	sp.addNumber(INT_MIN);
	sp.addNumber(INT_MAX);
	std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "longest span: " << sp.longestSpan() << std::endl;
}

void testLarge() {
	Span sp = Span(10000);
	std::vector<int> vec(10000, 42);
	vec[0] = 0;
	vec[9999] = 4242;

	sp.addNumber(vec.begin(), vec.end());
	std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "longest span: " << sp.longestSpan() << std::endl;
}

int main() {
	std::cout << "[Test 1]" << std::endl;
	testNormal();

	std::cout << std::endl << "[Test 2]" << std::endl;
	testException();

	std::cout << std::endl << "[Test 3]" << std::endl;
	testSpanMax();

	std::cout << std::endl << "[Test 4]" << std::endl;
	testLarge();
}

#include "PmergeMe.hpp"

size_t gCount = 0;

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) {
	(void) other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	(void) other;
	return *this;
}

PmergeMe::~PmergeMe() {}

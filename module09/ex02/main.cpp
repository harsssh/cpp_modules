#include <iostream>
#include "PmergeMe.hpp"

int main() {
	std::vector<int> vec;
	for (int i = 10; i >= 0; i--)
		vec.push_back(i);
	PmergeMe p(vec.begin(), vec.end());
	p.sortVector();
	std::cout << "vec: ";
	for (std::size_t i = 0; i < p.getVec().size(); ++i)
		std::cout << i << " ";
}

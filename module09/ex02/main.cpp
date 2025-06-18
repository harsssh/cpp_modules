#include <iostream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include "PmergeMe.hpp"

#define CLOCKS_PER_USEC (CLOCKS_PER_SEC / 1000000)

template<typename T>
std::ostream &operator<<(std::ostream &os, std::vector<T> const &v) {
	os << "[";
	for (typename std::vector<T>::const_iterator it = v.begin(); it != v.end(); it++) {
		if (it != v.begin())
			os << ", ";
		os << *it;
	}
	os << "]";
	return os;
}

int s2i(std::string const &s) {
	std::stringstream ss(s);
	int i;
	ss >> i;
	if (ss.fail() || !ss.eof())
		throw std::invalid_argument("s2i: invalid argument");
	return i;
}

template<typename Container>
void fillContainer(int argc, char **argv, Container &c) {
	for (int i = 1; i < argc; i++) {
		try {
			c.at(i - 1) = s2i(argv[i]);
			if (c.at(i - 1) < 0) {
				std::cout << "Error" << std::endl;
				std::exit(1);
			}
		} catch (std::exception &e) {
			std::cerr << "Error" << std::endl;
			std::exit(1);
		}
	}
}

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cout << "Usage: " << argv[0] << " [list of positive integers]" << std::endl;
		return 1;
	}

	std::vector<int> v(argc - 1);
	fillContainer(argc, argv, v);
	std::deque<int> d(argc - 1);
	fillContainer(argc, argv, d);

	std::cout << "Before:\t" << v << std::endl;

	// sort vector
	clock_t start = clock();
	PmergeMe::sort(v);
	clock_t end = clock();
	double vectorElapsed = (double) (end - start) / CLOCKS_PER_USEC;

	// sort deque
	start = clock();
	PmergeMe::sort(d);
	end = clock();
	double dequeElapsed = (double) (end - start) / CLOCKS_PER_USEC;

	std::cout << "After:\t" << v << std::endl;
	std::cout << "Time to process a range of " << std::setw(4) << v.size() << " elements with std::vector :\t"
			  << std::setw(8) << vectorElapsed << " us" << std::endl;
	std::cout << "Time to process a range of " << std::setw(4) << d.size() << " elements with std::deque :\t"
			  << std::setw(8) << dequeElapsed << " us" << std::endl;
}

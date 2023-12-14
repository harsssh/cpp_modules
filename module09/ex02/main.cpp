#include <iostream>
#include "PmergeMe.hpp"

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

int main() {
}

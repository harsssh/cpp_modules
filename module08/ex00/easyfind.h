#ifndef CPP_MODULES_EASYFIND_H
#define CPP_MODULES_EASYFIND_H

#include <algorithm>

// The first parameter has type T, which is a template parameter.
// The second parameter has type int.
// Assuming T is a container of integers.
// The function returns an iterator to the first occurrence of the second parameter in the container.
template<typename T>
typename T::iterator easyfind(T &container, int value) {
	return std::find(container.begin(), container.end(), value);
}

#endif //CPP_MODULES_EASYFIND_H

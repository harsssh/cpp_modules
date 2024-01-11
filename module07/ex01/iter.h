#ifndef CPP_MODULES_ITER_H
#define CPP_MODULES_ITER_H

#include <cstddef>

template<typename T>
void iter(T *array, size_t length, void (*func)(const T &)) {
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

template<typename T>
void iter(const T *array, size_t length, void (*func)(const T &)) {
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

template<typename T>
void iter(T *array, size_t length, void (*func)(T &)) {
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

#endif //CPP_MODULES_ITER_H

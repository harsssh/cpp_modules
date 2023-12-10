#ifndef CPP_MODULES_ARRAY_H
#define CPP_MODULES_ARRAY_H

#include <stdexcept>

template<typename T>
class Array {
public:
	Array() : array_(new T[0]), size_(0) {}

	Array(unsigned int n) : array_(new T[n]), size_(n) {}

	Array(const Array &other) : size_(other.size_) {
		array_ = new T[size_];
		for (unsigned int i = 0; i < size_; i++)
			array_[i] = other.array_[i];
	}

	Array &operator=(const Array &other) {
		if (this == &other)
			return *this;
		delete[] array_;
		size_ = other.size_;
		array_ = new T[size_];
		for (unsigned int i = 0; i < size_; i++)
			array_[i] = other.array_[i];
		return *this;
	}

	~Array() {
		delete[] array_;
	}

	T &operator[](unsigned int index) {
		if (index >= size_)
			throw std::out_of_range("Index out of range");
		return array_[index];
	}

	unsigned int size() {
		return size_;
	}

private:
	T *array_;
	unsigned int size_;
};

#endif //CPP_MODULES_ARRAY_H

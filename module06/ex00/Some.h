#ifndef CPP_MODULES_SOME_H
#define CPP_MODULES_SOME_H

#include "Option.h"

template<typename T>
class Some : public Option<T> {
public:
	Some() {}

	Some(T value) : value_(value) {}

	Some(const Some &other) : value_(other.value_) {}

	virtual ~Some() {}

	Some &operator=(const Some &other) {
		if (this != &other) {
			value_ = other.value_;
		}
		return *this;
	}

	T unwrap() const {
		return value_;
	}

	bool isSome() const {
		return true;
	}

private:
	T value_;
};

#endif //CPP_MODULES_SOME_H

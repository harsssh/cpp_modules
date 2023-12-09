#ifndef CPP_MODULES_NONE_H
#define CPP_MODULES_NONE_H

#include "Option.h"
#include <stdexcept>

template<typename T>
class None : public Option<T> {
public:
	None() {}

	None(const None &other) { (void) other; }

	virtual ~None() {}

	None &operator=(const None &other) {
		(void) other;
		return *this;
	}

	T unwrap() const throw(std::runtime_error) {
		throw std::runtime_error("called unwrap on a None value");
	}

	bool isSome() const {
		return false;
	}
};

#endif //CPP_MODULES_NONE_H

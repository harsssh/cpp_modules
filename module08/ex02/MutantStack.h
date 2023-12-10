#ifndef CPP_MODULES_MUTANTSTACK_H
#define CPP_MODULES_MUTANTSTACK_H

#include <vector>

template<typename T>
class MutantStack {
public:
	typedef typename std::vector<T>::reverse_iterator iterator;
	typedef typename std::vector<T>::iterator reverse_iterator;
	typedef typename std::vector<T>::size_type size_type;

	MutantStack() : vec_() {}

	MutantStack(const MutantStack &other) : vec_(other.vec_) {}

	~MutantStack() {}

	MutantStack &operator=(const MutantStack &other) {
		if (this != &other)
			vec_ = other.vec_;
		return *this;
	}

	// iterator
	iterator begin() {
		return vec_.rbegin();
	}

	reverse_iterator rbegin() {
		return vec_.begin();
	}

	iterator end() {
		return vec_.rend();
	}

	reverse_iterator rend() {
		return vec_.end();
	}

	// operations
	const T &top() const {
		return vec_.back();
	}

	bool empty() const {
		return vec_.empty();
	}

	void push(const T &val) {
		vec_.push_back(val);
	}

	void pop() {
		vec_.pop_back();
	}

	size_type size() const {
		return vec_.size();
	}

private:
	std::vector<T> vec_;
};

#endif //CPP_MODULES_MUTANTSTACK_H

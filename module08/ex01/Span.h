#ifndef CPP_MODULES_SPAN_H
#define CPP_MODULES_SPAN_H

#include <vector>
#include <set>
#include <stdexcept>

class Span {
public:
	Span();

	Span(unsigned int n);

	Span(const Span &other);

	~Span();

	Span &operator=(const Span &other);

	void addNumber(int num);

	template<class T>
	void addNumber(T begin, T end) {
		if (vec_.size() + std::distance(begin, end) > capacity_)
			throw std::runtime_error("Span is full");
		for (T it = begin; it != end; ++it)
			addNumber(*it);
	}

	unsigned int shortestSpan() const;

	unsigned int longestSpan() const;

	std::vector<int>::size_type size() const;

private:
	unsigned int capacity_;
	std::vector<int> vec_;
	std::multiset<unsigned int> span_;
};

#endif //CPP_MODULES_SPAN_H

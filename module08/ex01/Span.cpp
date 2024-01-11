#include "Span.h"

Span::Span() : capacity_(0) {}

Span::Span(unsigned int n) : capacity_(n) {
	vec_.reserve(n);
}

Span::Span(const Span &other) : capacity_(other.capacity_), vec_(other.vec_), span_(other.span_) {}

Span::~Span() {}

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		capacity_ = other.capacity_;
		vec_ = other.vec_;
		span_ = other.span_;
	}
	return *this;
}

void Span::addNumber(int num) {
	if (vec_.size() >= capacity_)
		throw std::runtime_error("Span is full");
	if (!vec_.empty()) {
		long diff = static_cast<long>(num) - static_cast<long>(vec_.back());
		unsigned int absDiff = static_cast<unsigned int>(diff < 0 ? -diff : diff);
		span_.insert(absDiff);
	}
	vec_.push_back(num);
}

unsigned int Span::shortestSpan() const {
	if (span_.empty())
		throw std::runtime_error("No span to calculate");
	return *span_.begin();
}

unsigned int Span::longestSpan() const {
	if (span_.empty())
		throw std::runtime_error("No span to calculate");
	return *span_.rbegin();
}

std::vector<int>::size_type Span::size() const {
	return vec_.size();
}

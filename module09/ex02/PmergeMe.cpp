#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : vec_(), deq_() {}

PmergeMe::PmergeMe(const PmergeMe &other) : vec_(other.vec_), deq_(other.deq_) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		vec_ = other.vec_;
		deq_ = other.deq_;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

const std::vector<int> &PmergeMe::getVec() const {
	return vec_;
}

const std::deque<int> &PmergeMe::getDeq() const {
	return deq_;
}

void PmergeMe::sortVector() {
	vectorMergeInsertionSort(vec_);
}

void PmergeMe::sortDeque() {
	dequeMergeInsertionSort(deq_);
}

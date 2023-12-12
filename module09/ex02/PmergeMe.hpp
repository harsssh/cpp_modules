#ifndef CPP_MODULES_PMERGEME_HPP
#define CPP_MODULES_PMERGEME_HPP

#include <vector>
#include <deque>
#include <utility>

class PmergeMe {
public:
	PmergeMe();

	template<typename T>
	PmergeMe(T begin, T end) : vec_(begin, end), deq_(begin, end) {}

	PmergeMe(PmergeMe const &other);

	PmergeMe &operator=(PmergeMe const &other);

	~PmergeMe();

	const std::vector<int> &getVec() const;

	const std::deque<int> &getDeq() const;

	void sortVector();

	void sortDeque();

private:
	std::vector<int> vec_;
	std::deque<int> deq_;
};

#endif //CPP_MODULES_PMERGEME_HPP

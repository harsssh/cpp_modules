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

	template<typename T>
	void vectorMergeInsertionSort(std::vector<T> &vec) {
		if (vec.size() < 2)
			return;

		bool hasUnpairedElement = (vec.size() % 2 != 0);

		// group elements into pairs
		// [larger, smaller]
		std::vector<std::pair<T, T> > pairs;
		pairs.reserve(vec.size() / 2);
		for (std::size_t i = 0; i + 1 < vec.size(); i += 2) {
			if (vec[i] < vec[i + 1])
				pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
			else
				pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
		}

		// sort pairs by first larger element
		vectorMergeInsertionSort<std::pair<T, T> >(pairs);

		// merge pairs
		std::vector<T> merged;
		for (std::size_t i = 0; i < pairs.size(); ++i)
			merged.push_back(pairs[i].first);
		// insert second element of pair
		std::vector<bool> inserted(pairs.size(), false);
		merged.push_back(pairs[0].second);
		inserted[0] = true;
		std::size_t prevIndex = 1;
		std::size_t currentIndex = 1;
		while (currentIndex < pairs.size()) {
			typename std::vector<T>::iterator it = std::lower_bound(merged.begin(), merged.end(),
																	pairs[currentIndex].second);
			merged.insert(it, pairs[currentIndex].second);
			inserted[currentIndex] = true;

			std::size_t tmp = prevIndex;
			prevIndex = currentIndex;
			currentIndex += 2 * tmp;
		}
		// insert remaining elements
		for (std::size_t i = 0; i < pairs.size(); ++i) {
			if (!inserted[i]) {
				typename std::vector<T>::iterator it = std::lower_bound(merged.begin(), merged.end(),
																		pairs[i].second);
				merged.insert(it, pairs[i].second);
			}
		}
		if (hasUnpairedElement) {
			typename std::vector<T>::iterator it = std::lower_bound(merged.begin(), merged.end(), vec.back());
			merged.insert(it, vec.back());
		}

		vec = merged;
	}

	template<typename T>
	void dequeMergeInsertionSort(std::deque<T> &deq) {
		if (deq.size() < 2)
			return;

		bool hasUnpairedElement = (deq.size() % 2 != 0);

		// group elements into pairs
		// [larger, smaller]
		std::deque<std::pair<T, T> > pairs;
		pairs.reserve(deq.size() / 2);
		for (std::size_t i = 0; i + 1 < deq.size(); i += 2) {
			if (deq[i] < deq[i + 1])
				pairs.push_back(std::make_pair(deq[i + 1], deq[i]));
			else
				pairs.push_back(std::make_pair(deq[i], deq[i + 1]));
		}

		// sort pairs by first larger element
		dequeMergeInsertionSort(pairs);

		// merge pairs
		std::deque<T> merged;
		for (std::size_t i = 0; i < pairs.size(); ++i)
			merged.push_back(pairs[i].first);
		// insert second element of pair
		std::deque<bool> inserted(pairs.size(), false);
		merged.push_back(pairs[0].second);
		inserted[0] = true;
		std::size_t prevIndex = 1;
		std::size_t currentIndex = 1;
		while (currentIndex < pairs.size()) {
			typename std::deque<T>::iterator it = std::lower_bound(merged.begin(), merged.end(),
																   pairs[currentIndex].second);
			merged.insert(it, pairs[currentIndex].second);
			inserted[currentIndex] = true;

			std::size_t tmp = prevIndex;
			prevIndex = currentIndex;
			currentIndex += 2 * tmp;
		}
		// insert remaining elements
		for (std::size_t i = 0; i < pairs.size(); ++i) {
			if (!inserted[i]) {
				typename std::deque<T>::iterator it = std::lower_bound(merged.begin(), merged.end(),
																	   pairs[i].second);
				merged.insert(it, pairs[i].second);
			}
		}
		if (hasUnpairedElement) {
			typename std::deque<T>::iterator it = std::lower_bound(merged.begin(), merged.end(), deq.back());
			merged.insert(it, deq.back());
		}

		deq = merged;
	};
};

#endif //CPP_MODULES_PMERGEME_HPP

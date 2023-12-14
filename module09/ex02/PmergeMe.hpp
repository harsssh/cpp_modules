#ifndef CPP_MODULES_PMERGEME_HPP
#define CPP_MODULES_PMERGEME_HPP

#include <vector>
#include <deque>

class PmergeMe {
public:
	PmergeMe();

	PmergeMe(PmergeMe const &other);

	PmergeMe &operator=(PmergeMe const &other);

	~PmergeMe();

	template<typename T>
	static void sort(std::vector<T> &v) {
		GroupIterator<typename std::vector<T>::iterator> begin(v.begin(), 1);
		GroupIterator<typename std::vector<T>::iterator> end(v.end(), 1);
		mergeInsertionSort(begin, end);
	}

	template<typename T>
	static void sort(std::deque<T> &d) {
		GroupIterator<typename std::deque<T>::iterator> begin(d.begin(), 1);
		GroupIterator<typename std::deque<T>::iterator> end(d.end(), 1);
		mergeInsertionSort(begin, end);
	}

private:
	template<typename Iterator>
	class GroupIterator {
	public:
		typedef typename std::iterator_traits<Iterator>::difference_type difference_type;
		typedef typename std::iterator_traits<Iterator>::value_type value_type;
		typedef typename std::iterator_traits<Iterator>::pointer pointer;
		typedef typename std::iterator_traits<Iterator>::reference reference;
		typedef typename std::iterator_traits<Iterator>::iterator_category iterator_category;
		typedef Iterator iterator_type;

		GroupIterator() : it_(), groupSize_() {}

		GroupIterator(Iterator it, difference_type groupSize) : it_(it), groupSize_(groupSize) {}

		GroupIterator(GroupIterator it, difference_type groupSize)
				: it_(it.it_), groupSize_(it.groupSize_ * groupSize) {}

		GroupIterator(GroupIterator const &other) : it_(other.it_), groupSize_(other.groupSize_) {}

		~GroupIterator() {}

		GroupIterator &operator=(GroupIterator const &other) {
			if (this != &other) {
				it_ = other.it_;
				groupSize_ = other.groupSize_;
			}
			return *this;
		}

		// dereference
		// returns a reference to the value of the last element of the group
		reference operator*() const {
			return *(it_ + groupSize_ - 1);
		}

		// increment
		// moves the iterator to the next group
		GroupIterator &operator++() {
			std::advance(it_, groupSize_);
			return *this;
		}

		GroupIterator &operator+=(difference_type n) {
			std::advance(it_, n * groupSize_);
			return *this;
		}

		// decrement
		// moves the iterator to the previous group
		GroupIterator &operator--() {
			std::advance(it_, -groupSize_);
			return *this;
		}

		// addition
		// moves the iterator forward by n groups
		GroupIterator operator+(difference_type n) const {
			GroupIterator tmp(*this);
			std::advance(tmp.it_, n * groupSize_);
			return tmp;
		}

		// subtraction
		// moves the iterator backward by n groups
		GroupIterator operator-(difference_type n) const {
			GroupIterator tmp(*this);
			std::advance(tmp.it_, -n * groupSize_);
			return tmp;
		}

		// difference
		// returns the number of groups between the two iterators
		difference_type operator-(GroupIterator const &other) const {
			return std::distance(other.it_, it_) / groupSize_;
		}

		// comparison
		// returns true if both iterators point to the same group
		bool operator==(GroupIterator const &other) const {
			return it_ == other.it_;
		}

		bool operator!=(GroupIterator const &other) const {
			return it_ != other.it_;
		}

		// iter_swap
		// swaps all the elements of the groups pointed to by the iterators
		void iter_swap(GroupIterator other) {
			for (difference_type i = 0; i < groupSize_; ++i)
				std::iter_swap(it_ + i, other.it_ + i);
		}

	private:
		Iterator it_;
		difference_type groupSize_;
	};

	template<typename T>
	static void binaryInsertion(std::vector<T> &v, const T &value) {
		typename std::vector<T>::iterator it = std::lower_bound(v.begin(), v.end(), value);
		v.insert(it, value);
	}

	template<typename Iterator>
	static void mergeInsertionSort(GroupIterator<Iterator> begin, GroupIterator<Iterator> end) {
		typename GroupIterator<Iterator>::difference_type size = std::distance(begin, end);
		if (size < 2)
			return ;

		bool hasUnpairedGroup = (size % 2 == 1);

		// sort in pairs of groups
		GroupIterator<Iterator> pairEnd = hasUnpairedGroup ? end - 1 : end;
		for (GroupIterator<Iterator> it = begin; it != pairEnd; it += 2) {
			if (*it > *(it + 1))
				it.iter_swap(it + 1);
		}

		// sort pairs of groups
		mergeInsertionSort(GroupIterator<Iterator>(begin, 2), GroupIterator<Iterator>(pairEnd, 2));

		// merge pairs of groups
		std::vector<typename GroupIterator<Iterator>::value_type> sorted;
		std::vector<typename GroupIterator<Iterator>::value_type> toBeInserted;
		for (GroupIterator<Iterator> it = begin; it != pairEnd; it += 2) {
			toBeInserted.push_back(*it);
			sorted.push_back(*(it + 1));
		}
		if (hasUnpairedGroup)
			toBeInserted.push_back(*pairEnd);
		// binary insertion sort
		// insertion order follows Jacobsthal numbers
		std::vector<bool> inserted(toBeInserted.size(), false);
		binaryInsertion(sorted, toBeInserted[0]);
		inserted[0] = true;
		std::size_t prevIndex = 0;
		std::size_t currentIndex = 1;
		while (currentIndex < toBeInserted.size()) {
			if (!inserted[currentIndex])
				binaryInsertion(sorted, toBeInserted[currentIndex]);
			std::size_t tmp = prevIndex;
			prevIndex = currentIndex;
			currentIndex += 2 * tmp;
		}
		for (std::size_t i = 0; i < toBeInserted.size(); ++i) {
			if (!inserted[i])
				binaryInsertion(sorted, toBeInserted[i]);
		}

		// copy sorted values
		for (std::size_t i = 0; i < sorted.size(); ++i)
			*(begin + i) = sorted[i];
	}
};

#endif //CPP_MODULES_PMERGEME_HPP

#ifndef CPP_MODULES_PMERGEME_HPP
#define CPP_MODULES_PMERGEME_HPP

#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>

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

		Iterator base() const {
			return it_;
		}

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
			std::advance<Iterator>(it_, groupSize_);
			return *this;
		}

		GroupIterator &operator+=(difference_type n) {
			std::advance<Iterator>(it_, n * groupSize_);
			return *this;
		}

		// addition
		// moves the iterator forward by n groups
		GroupIterator operator+(difference_type n) const {
			GroupIterator tmp(*this);
			std::advance<Iterator>(tmp.it_, n * groupSize_);
			return tmp;
		}

		// subtraction
		// moves the iterator backward by n groups
		GroupIterator operator-(difference_type n) const {
			GroupIterator tmp(*this);
			std::advance<Iterator>(tmp.it_, -n * groupSize_);
			return tmp;
		}

		// difference
		// returns the number of groups between the two iterators
		difference_type operator-(GroupIterator const &other) const {
			return std::distance(other.it_, it_) / groupSize_;
		}

		// comparison
		bool operator!=(GroupIterator const &other) const {
			return it_ != other.it_;
		}

		// iter_swap
		// swaps all the elements of the groups pointed to by the iterators
		void iter_swap(GroupIterator other) {
			for (difference_type i = 0; i < groupSize_; ++i)
				std::iter_swap(it_ + i, other.it_ + i);
		}

		static bool compare(const GroupIterator &lhs, const GroupIterator &rhs) {
			return *lhs < *rhs;
		}

		difference_type getGroupSize() const {
			return groupSize_;
		}

	private:
		Iterator it_;
		difference_type groupSize_;
	};

	template<typename T, typename Compare>
	static void binaryInsertion(
        std::vector<T> &v,
        std::size_t endIndex,
        const T &value,
        Compare comp
    ) {
		typename std::vector<T>::iterator it = std::lower_bound(v.begin(), v.begin() + endIndex, value, comp);
		v.insert(it, value);
	}

    /**
     * J(0) = 0, J(1) = 1, J(n) = J(n-1) + 2 * J(n-2)
     * {J(n)} = {0, 1, 1, 3, 5, 11, 21, ...}
     *
     * J(n) の index を起点に、逆順に挿入することを繰り返す
     * 挿入順: [0 (=J(0))], [1 (=J(1))], [3 (=J(3)), 2], [5 (=J(4)), 4], [11 (=J(5)), 10, ..., 6 ], ...
     */
    template<typename Iterator>
    static void insertion(std::vector<GroupIterator<Iterator> > &sortedGroups, std::vector<GroupIterator<Iterator> > &toBeInserted) {
        std::size_t binarySearchEndIndex = 0;

        sortedGroups.insert(sortedGroups.begin(), toBeInserted[0]);
        // 挿入した要素, それとペアになっていた main chain の要素分だけ検索範囲を増やす
        binarySearchEndIndex = std::min(binarySearchEndIndex + 2, sortedGroups.size());

        if (toBeInserted.size() < 2) return;

        // toBeInserted[1] の挿入位置を探す
        if (*toBeInserted[1] < *sortedGroups[0])
            sortedGroups.insert(sortedGroups.begin(), toBeInserted[1]);
        else if (*toBeInserted[1] < *sortedGroups[1])
            sortedGroups.insert(sortedGroups.begin() + 1, toBeInserted[1]);
        else
            sortedGroups.insert(sortedGroups.begin() + 2, toBeInserted[1]);
        binarySearchEndIndex = std::min(binarySearchEndIndex + 2, sortedGroups.size());

        std::size_t prevSeq = 1;
        std::size_t currentSeq = 3;
        while (true) {
            const std::size_t startIndex = std::min(currentSeq, toBeInserted.size() - 1);
            for (std::size_t i = startIndex; i > prevSeq; --i) {
                binaryInsertion(sortedGroups, binarySearchEndIndex, toBeInserted[i], GroupIterator<Iterator>::compare);
                binarySearchEndIndex = std::min(binarySearchEndIndex + 2, sortedGroups.size());
            }
            if (startIndex == toBeInserted.size() - 1) break;

            const std::size_t nextSeq = currentSeq + 2 * prevSeq;
            prevSeq = currentSeq;
            currentSeq = nextSeq;
        }
    }

	template<typename Iterator>
	static void mergeInsertionSort(GroupIterator<Iterator> begin, GroupIterator<Iterator> end) {
		typename GroupIterator<Iterator>::difference_type size = std::distance(begin, end);
		if (size < 2) return;
		bool hasUnpairedGroup = (size % 2 == 1);

        // merge sort のようにペアごとに比較、交換をする
		GroupIterator<Iterator> pairEnd = hasUnpairedGroup ? end - 1 : end;
		for (GroupIterator<Iterator> it = begin; it != pairEnd; it += 2) {
            // ペア (it, it+1) について、group の代表値が大きいほうが後になるように交換
			if (GroupIterator<Iterator>::compare(it + 1, it)) // *(it + 1) < *it
				it.iter_swap(it + 1);
		}

		// ペア単位で再帰的にソート
		mergeInsertionSort(GroupIterator<Iterator>(begin, 2), GroupIterator<Iterator>(pairEnd, 2));

        // ペアの先頭を toBeInserted に、末尾を sortedGroups に振り分ける
		std::vector<GroupIterator<Iterator> > sortedGroups;
		std::vector<GroupIterator<Iterator> > toBeInserted;
		for (GroupIterator<Iterator> it = begin; it != pairEnd; it += 2) {
			toBeInserted.push_back(it);
			sortedGroups.push_back(it + 1);
		}
		if (hasUnpairedGroup) toBeInserted.push_back(pairEnd);

        // insertion sort のようにソート列を構築
        insertion(sortedGroups, toBeInserted);

        // TODO: optimize
        // sortedGroups の group を分解して、begin...end に書き戻す
		std::vector<typename GroupIterator<Iterator>::value_type> tmp;
		for (typename std::vector<GroupIterator<Iterator> >::iterator it = sortedGroups.begin();
			 it != sortedGroups.end(); ++it) {
			for (typename GroupIterator<Iterator>::difference_type i = 0; i < it->getGroupSize(); ++i)
				tmp.push_back(*(it->base() + i));
		}
		std::copy(tmp.begin(), tmp.end(), begin.base());
	}
};

#endif //CPP_MODULES_PMERGEME_HPP

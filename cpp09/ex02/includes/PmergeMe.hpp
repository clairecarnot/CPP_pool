#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <algorithm>
# include <sstream>
# include <cstdlib>
# include <cctype>
# include <ctime>

class	PmergeMe
{
	public:
		PmergeMe(void);
		PmergeMe(PmergeMe const &src);
		~PmergeMe(void);

		PmergeMe	&operator=(PmergeMe const &src);

		void		mergeInsertVector(std::vector<int> *v);
		void		mergeInsertDeque(std::deque<int> *d);

	private:
		void		_sortInsidePairsVector(std::vector<int> *v, std::vector<int> *vbig, std::vector<int> *vsmall);
		void		_sortPairsVector(std::vector<int> *vbig, std::vector<int> *vsmall);
		void		_binaryInsertVector(std::vector<int> *v, std::vector<int> *vsmall);
		int		_dichotomyLoopVector(int beginPos, int endPos, int sVal, std::vector<int> *v);

		void		_sortInsidePairsDeque(std::deque<int> *d, std::deque<int> *dbig, std::deque<int> *dsmall);
		void		_sortPairsDeque(std::deque<int> *dbig, std::deque<int> *dsmall);
		void		_binaryInsertDeque(std::deque<int> *d, std::deque<int> *dsmall);
		int		_dichotomyLoopDeque(int beginPos, int endPos, int sVal, std::deque<int> *d);
};

#endif

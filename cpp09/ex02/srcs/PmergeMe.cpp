#include "PmergeMe.hpp"

// CONSTRUCTOR / DESTRUCTOR --------------------------------------------------- //

PmergeMe::PmergeMe(void)
{
}

PmergeMe::PmergeMe(PmergeMe const &src)
{
	*this = src;
}

PmergeMe::~PmergeMe(void)
{
}

// OPERATORS ------------------------------------------------------------------ //

PmergeMe	&PmergeMe::operator=(PmergeMe const &src)
{
	if (this != &src)
		return (*this);
	return (*this);
}

// GETTERS / SETTERS ---------------------------------------------------------- //


// FUNCTIONS ------------------------------------------------------------------ //

// VECTOR ------------------------------------------------------------------ //

void	PmergeMe::mergeInsertVector(std::vector<int> *v)
{
	if (v->size() == 1)
		return ;
	if (v->size() == 2)
	{
		if ((*v)[0] > (*v)[1])
		{
			int tmp = (*v)[0];
			(*v)[0] = (*v)[1];
			(*v)[1] = tmp;
		}
		return ;
	}

	std::vector<int>	*vbig = new(std::vector<int>);
	std::vector<int>	*vsmall = new(std::vector<int>);

	_sortInsidePairsVector(v, vbig, vsmall);
//	_sortPairsVector(vbig, vsmall);
	_mergeSortVector(vbig, vsmall);
	v->assign(vbig->begin(), vbig->end());
	v->insert(v->begin(), *vsmall->begin());

	_binaryInsertVector(v, vsmall);

	delete vbig;
	delete vsmall;
}

void	PmergeMe::_sortInsidePairsVector(std::vector<int> *v, std::vector<int> *vbig, std::vector<int> *vsmall)
{
	std::size_t i = 0;
	while (i < v->size())
	{
		if (i + 1 >= v->size())
			vsmall->push_back((*v)[i]);
		else if ((*v)[i + 1] > (*v)[i])
		{
			vbig->push_back((*v)[i + 1]);
			vsmall->push_back((*v)[i]);
		}
		else
		{
			vsmall->push_back((*v)[i + 1]);
			vbig->push_back((*v)[i]);
		}
		i += 2;
	}
}

/*
void	PmergeMe::_sortPairsVector(std::vector<int> *vbig, std::vector<int> *vsmall)
{
	size_t	i = 0;
	int	tmp;

	while (i < vbig->size())
	{
		size_t j = i + 1;
		while (j < vbig->size())
		{
			if ((*vbig)[i] > (*vbig)[j])
			{
				tmp = (*vbig)[i];
				(*vbig)[i] = (*vbig)[j];
				(*vbig)[j] = tmp;

				tmp = (*vsmall)[i];
				(*vsmall)[i] = (*vsmall)[j];
				(*vsmall)[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
*/

void	PmergeMe::_mergeSortVector(std::vector<int> *vbig, std::vector<int> *vsmall)
{
	size_t len = vbig->size();
	if (len <= 1)
		return ;
	size_t	mid = len / 2;
	std::vector<int> *vbl = new std::vector<int>;
	std::vector<int> *vbr = new std::vector<int>;
	std::vector<int> *vsl = new std::vector<int>;
	std::vector<int> *vsr = new std::vector<int>;

	size_t i = 0;
	for (; i < len; i++)
	{
		if (i < mid)
		{
			vbl->push_back((*vbig)[i]);
			vsl->push_back((*vsmall)[i]);
		}
		else
		{
			vbr->push_back((*vbig)[i]);
			vsr->push_back((*vsmall)[i]);
		}
	}
	PmergeMe::_mergeSortVector(vbl, vsl);
	PmergeMe::_mergeSortVector(vbr, vsr);
	PmergeMe::_mergeVector(vbig, vbl, vbr, vsmall, vsl, vsr);

	delete vbl;
	delete vbr;
	delete vsl;
	delete vsr;
}

void	PmergeMe::_mergeVector(std::vector<int> *vbig, std::vector<int> *vbl, std::vector<int> *vbr, std::vector<int> *vsmall, std::vector<int> *vsl, std::vector<int> *vsr)
{
	size_t leftLen = vbig->size() / 2;
	size_t rightLen = vbig->size() - leftLen;

	size_t i(0);
	size_t l(0);
	size_t r(0);
	while (l < leftLen && r < rightLen)
	{
		if ((*vbl)[l] < (*vbr)[r])
		{
			(*vbig)[i] = (*vbl)[l];
			(*vsmall)[i] = (*vsl)[l];
			i++;
			l++;
		}
		else
		{
			(*vbig)[i] = (*vbr)[r];
			(*vsmall)[i] = (*vsr)[r];
			i++;
			r++;
		}
	}
	while (l < leftLen)
	{
		(*vbig)[i] = (*vbl)[l];
		(*vsmall)[i] = (*vsl)[l];
		i++;
		l++;
	}
	while (r < rightLen)
	{
		(*vbig)[i] = (*vbr)[r];
		(*vsmall)[i] = (*vsr)[r];
		i++;
		r++;
	}

}

void	PmergeMe::_binaryInsertVector(std::vector<int> *v, std::vector<int> *vsmall)
{
	std::vector<int> pos;
	std::size_t	size = vsmall->size();
	if (size % 2 != 0)
		size--; // if odd size, don't take last number into account
	
	for (std::size_t i = 0; i < size; i++)
		pos.push_back(i + 1);

	int jacobN(3), jacobN_1(1), jacobN_2(1), jacobtmp(3);

	int sVal = 0;
	int endPos = 0;
	int beginPos = 0;
	int mid = 0;
	std::size_t i = 0;
	while (i < size - 1) // -1 because smallest value (index 0) was already merged
	{
		if (i != 0)
		{
			jacobtmp = jacobN;
			jacobN = jacobN_1 + 2 * jacobN_2;
			jacobN_2 = jacobN_1;
			jacobN_1 = jacobtmp;
			jacobtmp = jacobN;
		}

		while (jacobtmp != jacobN_1)
		{
			if (jacobtmp - 1 < static_cast<int>(size))
			{
				sVal = (*vsmall)[jacobtmp - 1];

				endPos = pos[jacobtmp - 1];
				beginPos = 0;

				mid = _dichotomyLoopVector(beginPos, endPos, sVal, v);
				if (sVal > (*v)[mid])
				{
					std::vector<int>::iterator it = lower_bound(pos.begin(), pos.end(), mid + 1);
					for (; it != pos.end(); ++it)
						*it += 1;
					v->insert(v->begin() + mid + 1, sVal);
				}
				else
				{
					std::vector<int>::iterator it = lower_bound(pos.begin(), pos.end(), mid);
					for (; it != pos.end(); ++it)
						*it += 1;
					v->insert(v->begin() + mid, sVal);
				}
				i++;
				jacobtmp--;
			}
			else
				jacobtmp = static_cast<int>(size) + 1;
		}
	}
	if (++i < vsmall->size())
	{
		int sVal = *(vsmall->end() - 1);
		int endPos = v->size() - 1;
		int beginPos = 0;
		mid = _dichotomyLoopVector(beginPos, endPos, sVal, v);
		if (sVal > (*v)[mid])
		{
			for (std::size_t i = mid + 1; i < pos.size(); i++)
				pos[i] += 1;
			v->insert(v->begin() + mid + 1, sVal);
		}
		else
		{
			for (std::size_t i = mid - 1; i < pos.size(); i++)
				pos[i] += 1;
			v->insert(v->begin() + mid, sVal);
		}
	}
}

int	PmergeMe::_dichotomyLoopVector(int beginPos, int endPos, int sVal, std::vector<int> *v)
{
	int mid = 0;

	while (beginPos <= endPos)
	{
		if (beginPos == endPos)
			return (beginPos);
		mid = beginPos + (endPos - beginPos)/2;
		if (sVal > (*v)[mid])
			beginPos = mid + 1;
		else if (sVal < (*v)[mid])
			endPos = mid - 1;
	}
	return (mid);
}

// DEQUE ------------------------------------------------------------------ //

void	PmergeMe::mergeInsertDeque(std::deque<int> *d)
{
	if (d->size() == 1)
		return ;
	if (d->size() == 2)
	{
		if ((*d)[0] > (*d)[1])
		{
			int tmp = (*d)[0];
			(*d)[0] = (*d)[1];
			(*d)[1] = tmp;
		}
		return ;
	}

	std::deque<int>	*dbig = new(std::deque<int>);
	std::deque<int>	*dsmall = new(std::deque<int>);

	_sortInsidePairsDeque(d, dbig, dsmall);
//	_sortPairsDeque(dbig, dsmall);
	_mergeSortDeque(dbig, dsmall);
	d->assign(dbig->begin(), dbig->end());
	d->insert(d->begin(), *dsmall->begin());

	_binaryInsertDeque(d, dsmall);

	delete dbig;
	delete dsmall;
}

void	PmergeMe::_sortInsidePairsDeque(std::deque<int> *d, std::deque<int> *dbig, std::deque<int> *dsmall)
{
	std::size_t i = 0;
	while (i < d->size())
	{
		if (i + 1 >= d->size())
			dsmall->push_back((*d)[i]);
		else if ((*d)[i + 1] > (*d)[i])
		{
			dbig->push_back((*d)[i + 1]);
			dsmall->push_back((*d)[i]);
		}
		else
		{
			dsmall->push_back((*d)[i + 1]);
			dbig->push_back((*d)[i]);
		}
		i += 2;
	}
}

/*
void	PmergeMe::_sortPairsDeque(std::deque<int> *dbig, std::deque<int> *dsmall)
{
	size_t	i = 0;
	int	tmp;

	while (i < dbig->size())
	{
		size_t j = i + 1;
		while (j < dbig->size())
		{
			if ((*dbig)[i] > (*dbig)[j])
			{
				tmp = (*dbig)[i];
				(*dbig)[i] = (*dbig)[j];
				(*dbig)[j] = tmp;

				tmp = (*dsmall)[i];
				(*dsmall)[i] = (*dsmall)[j];
				(*dsmall)[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
*/

void	PmergeMe::_mergeSortDeque(std::deque<int> *dbig, std::deque<int> *dsmall)
{
	size_t len = dbig->size();
	if (len <= 1)
		return ;
	size_t	mid = len / 2;
	std::deque<int> *dbl = new std::deque<int>;
	std::deque<int> *dbr = new std::deque<int>;
	std::deque<int> *dsl = new std::deque<int>;
	std::deque<int> *dsr = new std::deque<int>;

	size_t i = 0;
	for (; i < len; i++)
	{
		if (i < mid)
		{
			dbl->push_back((*dbig)[i]);
			dsl->push_back((*dsmall)[i]);
		}
		else
		{
			dbr->push_back((*dbig)[i]);
			dsr->push_back((*dsmall)[i]);
		}
	}
	PmergeMe::_mergeSortDeque(dbl, dsl);
	PmergeMe::_mergeSortDeque(dbr, dsr);
	PmergeMe::_mergeDeque(dbig, dbl, dbr, dsmall, dsl, dsr);

	delete dbl;
	delete dbr;
	delete dsl;
	delete dsr;
}

void	PmergeMe::_mergeDeque(std::deque<int> *dbig, std::deque<int> *dbl, std::deque<int> *dbr, std::deque<int> *dsmall, std::deque<int> *dsl, std::deque<int> *dsr)
{
	size_t leftLen = dbig->size() / 2;
	size_t rightLen = dbig->size() - leftLen;

	size_t i(0);
	size_t l(0);
	size_t r(0);
	while (l < leftLen && r < rightLen)
	{
		if ((*dbl)[l] < (*dbr)[r])
		{
			(*dbig)[i] = (*dbl)[l];
			(*dsmall)[i] = (*dsl)[l];
			i++;
			l++;
		}
		else
		{
			(*dbig)[i] = (*dbr)[r];
			(*dsmall)[i] = (*dsr)[r];
			i++;
			r++;
		}
	}
	while (l < leftLen)
	{
		(*dbig)[i] = (*dbl)[l];
		(*dsmall)[i] = (*dsl)[l];
		i++;
		l++;
	}
	while (r < rightLen)
	{
		(*dbig)[i] = (*dbr)[r];
		(*dsmall)[i] = (*dsr)[r];
		i++;
		r++;
	}

}

void	PmergeMe::_binaryInsertDeque(std::deque<int> *d, std::deque<int> *dsmall)
{
	std::deque<int> pos;
	std::size_t	size = dsmall->size();
	if (size % 2 != 0)
		size--; // if odd size, don't take last number into account
	
	for (std::size_t i = 0; i < size; i++)
		pos.push_back(i + 1);

	int jacobN(3), jacobN_1(1), jacobN_2(1), jacobtmp(3);

	int sVal = 0;
	int endPos = 0;
	int beginPos = 0;
	int mid = 0;
	std::size_t i = 0;
	while (i < size - 1) // -1 because smallest value (index 0) was already merged
	{
		if (i != 0)
		{
			jacobtmp = jacobN;
			jacobN = jacobN_1 + 2 * jacobN_2;
			jacobN_2 = jacobN_1;
			jacobN_1 = jacobtmp;
			jacobtmp = jacobN;
		}

		while (jacobtmp != jacobN_1)
		{
			if (jacobtmp - 1 < static_cast<int>(size))
			{
				sVal = (*dsmall)[jacobtmp - 1];

				endPos = pos[jacobtmp - 1];
				beginPos = 0;

				mid = _dichotomyLoopDeque(beginPos, endPos, sVal, d);
				if (sVal > (*d)[mid])
				{
					std::deque<int>::iterator it = lower_bound(pos.begin(), pos.end(), mid + 1);
					for (; it != pos.end(); ++it)
						*it += 1;
					d->insert(d->begin() + mid + 1, sVal);
				}
				else
				{
					std::deque<int>::iterator it = lower_bound(pos.begin(), pos.end(), mid);
					for (; it != pos.end(); ++it)
						*it += 1;
					d->insert(d->begin() + mid, sVal);
				}
				i++;
			}
			jacobtmp--;
		}
	}
	if (++i < dsmall->size())
	{
		int sVal = *(dsmall->end() - 1);
		int endPos = d->size() - 1;
		int beginPos = 0;
		mid = _dichotomyLoopDeque(beginPos, endPos, sVal, d);
		if (sVal > (*d)[mid])
		{
			for (std::size_t i = mid + 1; i < pos.size(); i++)
				pos[i] += 1;
			d->insert(d->begin() + mid + 1, sVal);
		}
		else
		{
			for (std::size_t i = mid - 1; i < pos.size(); i++)
				pos[i] += 1;
			d->insert(d->begin() + mid, sVal);
		}
	}
}

int	PmergeMe::_dichotomyLoopDeque(int beginPos, int endPos, int sVal, std::deque<int> *d)
{
	int mid = 0;

	while (beginPos <= endPos)
	{
		if (beginPos == endPos)
			return (beginPos);
		mid = beginPos + (endPos - beginPos)/2;
		if (sVal > (*d)[mid])
			beginPos = mid + 1;
		else if (sVal < (*d)[mid])
			endPos = mid - 1;
	}
	return (mid);
}

// STATIC ELEMENTS ------------------------------------------------------------ //



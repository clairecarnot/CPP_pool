#include "Span.hpp"

// CONSTRUCTORS / DESTRUCTOR ---------------------------------------------------------- // 

Span::Span(unsigned int N) : _N(N)
{
}

Span::Span(Span const &src) : _nums(src._nums), _N(src._N)
{
}

Span::~Span(void)
{
}

// OPERATORS -------------------------------------------------------------------------- // 

Span	&Span::operator=(Span const &src)
{
	if (this != &src)
	{
		this->_nums = src._nums;
		this->_N = src._N;
	}
	return (*this);
}

std::ostream	&operator<<(std::ostream &os, Span const &span)
{
	os << "Span : { ";
	for (std::vector<int>::const_iterator it = span.getNums().begin();
			it != span.getNums().end(); ++it)
	{
		if (it != span.getNums().begin())
			os << ", ";
		os << *it;
	}
	os << " }";
	return (os);
}

// GETTERS / SETTERS ------------------------------------------------------------------ // 

std::vector<int> const	&Span::getNums(void) const
{
	return (this->_nums);
}

// FUNCTIONS -------------------------------------------------------------------------- // 

void	Span::addNumber(int n)
{
	if (this->_nums.size() < this->_N)
		this->_nums.push_back(n);
	else
		throw Span::StorageFullException();
}

void	Span::addNumberRange(std::vector<int> v)
{
	if (this->_nums.size() >= this->_N)
		throw StorageFullException();
	else if (this->_nums.size() + v.size() > this->_N)
		throw NotEnoughSpaceException();
	else
		this->_nums.insert(this->_nums.end(), v.begin(), v.end());
}

unsigned int	Span::shortestSpan() const
{
	if (this->_nums.size() > 1)
	{
		unsigned int shortestSpan = 4294967295;

		std::vector<int> sorted(this->_nums);
		std::sort(sorted.begin(), sorted.end());
		
		std::vector<int> diff(sorted);
		std::adjacent_difference(sorted.begin(), sorted.end(), diff.begin());

		shortestSpan = *std::min_element(++(diff.begin()), diff.end());
		return (shortestSpan);
	}
	else
		throw Span::StorageBelowMinException();
}

unsigned int	Span::longestSpan() const
{
	if (this->_nums.size() > 1)
	{
		std::vector<int>::const_iterator max = std::max_element(this->_nums.begin(), this->_nums.end());
		std::vector<int>::const_iterator min = std::min_element(this->_nums.begin(), this->_nums.end());
		return (*max - *min);
	}
	else
		throw Span::StorageBelowMinException();
}

// STATIC ELEMENTS -------------------------------------------------------------------- // 



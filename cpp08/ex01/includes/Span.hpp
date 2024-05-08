#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <numeric>
# include <iterator>

class	Span
{
	public:
		Span(unsigned int N);
		Span(Span const &src);
		~Span(void);

		class	StorageFullException : public std::exception
		{
			public:
				virtual const char*	what(void) const throw()
				{
					return ("Storage is already full !");
				}
		};

		class	StorageBelowMinException : public std::exception
		{
			public:
				virtual const char*	what(void) const throw()
				{
					return ("Cannot find Span because there is less than 2 numbers stored!");
				}
		};

		class	NotEnoughSpaceException : public std::exception
		{
			public:
				virtual const char*	what(void) const throw()
				{
					return ("Too many items to add : not enough space in storage !");
				}
		};

		Span	&operator=(Span const &src);

		std::vector<int> const	&getNums(void) const;

		void	addNumber(int n);
		void	addNumberRange(std::vector<int> v);
		unsigned int	shortestSpan(void) const;
		unsigned int	longestSpan() const;

	private:
		Span(void);
		std::vector<int>	_nums;
		unsigned int		_N;
};

std::ostream	&operator<<(std::ostream &os, Span const &span);

#endif

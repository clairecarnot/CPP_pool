#ifndef ARRAY_HPP
# define ARRAY_HPP

# define MAX_VAL 750

# include <iostream>
# include <exception>
# include <cstdlib>

template <typename T = int>
class Array
{
	public:
		// Constructors and destructor
		Array(void) : _array(NULL), _n(0) {}

		Array(unsigned int const &n) : _array(new T[n]), _n(n)
		{
			for (unsigned int i = 0; i < n; i++)
				this->_array[i] = 0;
		}

		Array(Array const &src) : _array(new T[src._n]), _n(src._n)
		{
			for (unsigned int i = 0; i < src._n; i++)
				this->_array[i] = src._array[i];
		}

		~Array(void)
		{
			if (this->_array)
				delete [] this->_array;
		}

		// Exceptions
		class OutOfBondsException : public std::exception
		{
			public:
				virtual const char*	what() const throw()
				{
					return ("[] index is out of bonds for this array !");
				}
		};

		// Operators
		Array	&operator=(Array const &src)
		{
			if (this != &src)
			{
				if (this->_array)
					delete [] this->_array;
				this->_array = new T[src._n];
				for (unsigned int i = 0; i < src._n; i++)
					this->_array[i] = src._array[i];
				this->_n = src._n;
			}
			return (*this);
		}

		T	&operator[](unsigned int const &index)
		{
			if (index >= this->_n)
				throw OutOfBondsException();
			else
				return (this->_array[index]);
		}

		T const &operator[](unsigned int const &index) const
		{
			if (index >= this->_n)
				throw OutOfBondsException();
			else
				return (this->_array[index]);
		}

		// Functions
		unsigned int	size(void) const
		{
			return (this->_n);
		}

	private:
		T		*_array;
		unsigned int	_n;
};

// To print the entire Array object
template <typename T>
std::ostream	&operator<<(std::ostream &os, const Array<T> &a)
{
	os << "{ ";
	for (unsigned int i = 0; i < a.size(); ++i)
	{
		os << a[i];
		if (i != a.size() - 1)
			os << ", ";
	}
	os << " };";
	return (os);
}

#endif

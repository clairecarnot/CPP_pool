#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <vector>
# include <deque>
# include <list>

template<typename T, typename C = std::deque<T> >
class	MutantStack : public std::stack<T, C>
{
	public:
		MutantStack<T, C>(void) : std::stack<T, C>() {};
		MutantStack<T, C>(MutantStack<T, C> const &src) : std::stack<T,C>(src) {};
		explicit MutantStack<T, C>(C const &c) : std::stack<T,C>(c) {};
		~MutantStack<T, C>(void) {};

		MutantStack<T, C>	&operator=(MutantStack<T, C> const &src)
		{
			if (this != &src)
				this->c = src.c;
			return (*this);
		}

		typedef typename std::stack<T, C>::container_type::iterator iterator;
		iterator begin() {return this->c.begin();};
		iterator end() {return this->c.end();};

		typedef typename std::stack<T, C>::container_type::reverse_iterator riterator;
		riterator rbegin() {return this->c.rbegin();};
		riterator rend() {return this->c.rend();};

};

/*
 Works with the tests but missing the 2nd parameter of constructor Stack
 
template<typename T>
class	MutantStack : public std::stack<T>
{
	public:
		MutantStack(void) {};
		MutantStack(MutantStack const &src) {*this = src;};
		~MutantStack(void) {};

		MutantStack	&operator=(MutantStack const &src)
		{
			if (this != &src)
				return (*this);
			return (*this);
		}

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin() {return this->c.begin();};
		iterator end() {return this->c.end();};

		typedef typename std::stack<T>::container_type::reverse_iterator riterator;
		riterator rbegin() {return this->c.rbegin();};
		riterator rend() {return this->c.rend();};

};
*/

#endif

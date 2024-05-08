#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <iterator>
# include <stdexcept>
# include <vector>
# include <deque>
# include <list>

template <typename T>
typename T::const_iterator	easyfind(T const &container, int const &n)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw (std::out_of_range("Item not found !"));
	else
		return (it);
}

#endif

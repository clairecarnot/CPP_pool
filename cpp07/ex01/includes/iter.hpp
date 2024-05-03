#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T, typename F>
void	iter(T *a, size_t const &length, F const &function)
{
	for (size_t i = 0; i < length; i++)
		function(a[i]);
}

template <typename T>
void	display(T const &x)
{
	std::cout << x << std::endl;
}

template <typename T>
void	increment(T &x)
{
	x++;
}

#endif

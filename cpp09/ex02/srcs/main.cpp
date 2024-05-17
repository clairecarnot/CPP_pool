#include "Colors.hpp"
#include "PmergeMe.hpp"

template <typename T>
void	sortCheck(T const &container)
{
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
	{
		if (it != container.begin())
		{
			if (*it < *(it - 1))
			{
				std::cout << RED "Error : output incorrectly sorted." RESET << std::endl;
				std::cout << *it << std::endl;
				std::cout << *(it - 1) << std::endl;
				return ;
			}
		}
	}
	std::cout << LGREEN "OK - output well sorted." RESET << std::endl;
}

int	parse(std::string const &input)
{
	if (input.empty())
		return (-1);

	int i = 0;
	if (input[0] == '-')
		i++;
	while (input[i])
	{
		if (!isdigit(input[i]))
			return (-1);
		i++;
	}

	std::istringstream iss(input);
	int number;

	iss >> number;
	if (iss.fail())
		return (-1);

	if (number < 0 || number > 2147483647)
		return (-1);

	return (number);
}

bool	duplicatesCheckVector(std::vector<int> const *v)
{
	for (std::vector<int>::const_iterator it = v->begin(); it != v->end(); ++it)
	{
		if (find(it + 1, v->end(), *it) != v->end())
			return (true);
	}
	return (false);
}

bool	duplicatesCheckDeque(std::deque<int> const *d)
{
	for (std::deque<int>::const_iterator it = d->begin(); it != d->end(); ++it)
	{
		if (find(it + 1, d->end(), *it) != d->end())
			return (true);
	}
	return (false);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		// Vector:
		std::clock_t vt;
		vt = std::clock();

		PmergeMe		pmmv;
		std::vector<int>	*v = new (std::vector<int>);

		std::string inputv;
		int varg;
		int i = 1;
		while (argv[i])
		{
			inputv = argv[i];
			varg = parse(inputv);
			if (varg >= 0)
				v->push_back(varg);
			else
			{
				std::cout << "Error" << std::endl;
				delete v;
				return (0);
			}
			i++;
		}
		if (duplicatesCheckVector(v))
		{
			std::cout << "Error" << std::endl;
			delete v;
			return (0);
		}

//		sortCheck(*v);
		pmmv.mergeInsertVector(v);
		vt = std::clock() - vt;

		// Deque:
		std::clock_t dt;
		dt = std::clock();

		PmergeMe		pmmd;
		std::deque<int>		*d = new (std::deque<int>);

		std::string inputd;
		int darg;
		int j = 1;
		while (argv[j])
		{
			inputd = argv[j];
			darg = parse(inputd);
			if (darg >= 0)
				d->push_back(darg);
			else
			{
				std::cout << "Error" << std::endl;
				delete v;
				delete d;
				return (0);
			}
			j++;
		}
		if (duplicatesCheckDeque(d))
		{
			std::cout << "Error" << std::endl;
			delete v;
			delete d;
			return (0);
		}

//		sortCheck(*d);
		pmmd.mergeInsertDeque(d);
		dt = std::clock() - dt;

		// Display
		i = 1;
		std::cout << "Before : ";
		while (argv[i])
		{
			std::cout << argv[i] << " ";
			i++;
		}
		std::cout << std::endl;

		std::cout << "After : ";
		for (std::vector<int>::const_iterator it = v->begin(); it != v->end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
//		std::cout << "After : ";
//		for (std::deque<int>::const_iterator it = d->begin(); it != d->end(); ++it)
//			std::cout << *it << " ";
//		std::cout << std::endl;

		std::cout << "Time to process a range of " <<  argc - 1 << " elements with std::vector<int> : " << static_cast<float>(vt)/CLOCKS_PER_SEC  << " seconds" << std::endl;
//		sortCheck(*v);
		std::cout << "Time to process a range of " <<  argc - 1 << " elements with std::deque<int> : " << static_cast<float>(dt)/CLOCKS_PER_SEC  << " seconds" << std::endl;
//		sortCheck(*d);

		delete v;
		delete d;
	}
	else
		std::cout << "Error" << std::endl;

	return (0);
}

/*
int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		PmergeMe		pmm;
		std::vector<int>	*v = new (std::vector<int>);
		std::deque<int>		*d = new (std::deque<int>);

		std::string input;
		int arg;
		int i = 1;
		while (argv[i])
		{
			input = argv[i];
			arg = parse(input);
			if (arg >= 0)
			{
				v->push_back(arg);
				d->push_back(arg);
			}
			else
			{
				std::cout << "Error" << std::endl;
				delete v;
				delete d;
				return (0);
			}
			i++;
		}
		if (duplicatesCheck(v))
		{
			std::cout << "Error" << std::endl;
			delete v;
			delete d;
			return (0);
		}

		std::cout << "Before : ";
		for (std::vector<int>::const_iterator it = v->begin(); it != v->end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

//		std::cout << "Before : ";
//		for (std::deque<int>::const_iterator it = d->begin(); it != d->end(); ++it)
//			std::cout << *it << " ";
//		std::cout << std::endl;

//		sortCheck(*v);
//		sortCheck(*d);

		std::clock_t vt;
		vt = std::clock();
		pmm.mergeInsertVector(v);
		vt = std::clock() - vt;

		std::clock_t dt;
		dt = std::clock();
		pmm.mergeInsertDeque(d);
		dt = std::clock() - dt;

		std::cout << "After : ";
		for (std::vector<int>::const_iterator it = v->begin(); it != v->end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

//		std::cout << "After : ";
//		for (std::deque<int>::const_iterator it = d->begin(); it != d->end(); ++it)
//			std::cout << *it << " ";
//		std::cout << std::endl;

		std::cout << "Time to process a range of " <<  argc - 1 << " elements with std::vector<int> : " << static_cast<float>(vt)/CLOCKS_PER_SEC  << " seconds" << std::endl;
//		sortCheck(*v);
		std::cout << "Time to process a range of " <<  argc - 1 << " elements with std::deque<int> : " << static_cast<float>(dt)/CLOCKS_PER_SEC  << " seconds" << std::endl;
//		sortCheck(*d);

		delete v;
		delete d;
	}
	else
		std::cout << "Error" << std::endl;

	return (0);
}
*/

#include "easyfind.hpp"
#include "Colors.hpp"

template <typename T>
void	testContainer(std::string type, T const &container, int const &n)
{
	std::cout << "Searching for value " << n << " in " << type << ": " << std::endl;
	std::cout << "{ ";
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
	{
		if (it != container.begin())
			std::cout << ", ";
		std::cout << *it;
	}
	std::cout << " }" << std::endl;
	try
	{
		typename T::const_iterator it;
		it = easyfind(container, n);
		std::cout << LGREEN "Success ! item was found." RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

int	main(void)
{
	{
		std::cout << ABLUE "// Test : int vectors ---------------------------- //" RESET << std::endl;

		std::vector<int> container;
		container.push_back(-1);
		container.push_back(0);
		container.push_back(1);
		container.push_back(2);
		container.push_back(3);

		testContainer("Vector", container, 2);
		std::cout << std::endl;
		testContainer("Vector", container, -5);
		std::cout << std::endl;
	}
	{
		std::cout << ABLUE "// Test : char vectors --------------------------- //" RESET << std::endl;

		std::vector<char> container;
		container.push_back('a');
		container.push_back('b');
		container.push_back('c');
		container.push_back('d');
		container.push_back('e');

		testContainer("Vector", container, 98);
		std::cout << std::endl;
		testContainer("Vector", container, -1);
		std::cout << std::endl;
	}
	{
		std::cout << ABLUE "// Test : int deques ----------------------------- //" RESET << std::endl;

		std::deque<int> container;
		container.push_back(-895);
		container.push_back(45);
		container.push_back(-7);
		container.push_back(-33);
		container.push_back(194);

		testContainer("Deque", container, -7);
		std::cout << std::endl;
		testContainer("Deque", container, 13);
		std::cout << std::endl;
	}
	{
		std::cout << ABLUE "// Test : int lists ------------------------------ //" RESET << std::endl;

		std::list<int> container;
		container.push_back(2147483647);
		container.push_back(672);
		container.push_back(-159);
		container.push_back(3);
		container.push_back(-2147483648);

		testContainer("List", container, -2147483648);
		std::cout << std::endl;
		testContainer("List", container, -66);
		std::cout << std::endl;
	}
	return (0);
}

#include "Colors.hpp"
#include "iter.hpp"

void	testString(void)
{
	std::cout << ABLUE "// Test on String --------------------------- // " RESET << std::endl;

	std::string a[] = {"hello", "hey", "bonjour"};

	::iter(a, 3, ::display<std::string>);
	std::cout << std::endl;
}

void	testDouble(void)
{
	std::cout << ABLUE "// Test on Double --------------------------- // " RESET << std::endl;

	double a[] = {101.6, -50.21, 601.7, -0.04};

	::iter(a, 4, ::display<double>);
	std::cout << std::endl;

	::iter(a, 4, ::increment<double>);

	::iter(a, 4, ::display<double>);
	std::cout << std::endl;
}

void	testFloat(void)
{
	std::cout << ABLUE "// Test on Float ---------------------------- // " RESET << std::endl;

	float a[] = {-5.01f, 200.16f};

	::iter(a, 2, ::display<float>);
	std::cout << std::endl;

	::iter(a, 2, ::increment<float>);

	::iter(a, 2, ::display<float>);
	std::cout << std::endl;
}

void	testInt(void)
{
	std::cout << ABLUE "// Test on Int ------------------------------ // " RESET << std::endl;

	int a[] = {-1, 0, 1, 2};

	::iter(a, 4, ::display<int>);
	std::cout << std::endl;

	::iter(a, 4, ::increment<int>);

	::iter(a, 4, ::display<int>);
	std::cout << std::endl;
}

void	testChar(void)
{
	std::cout << ABLUE "// Test on Char ----------------------------- // " RESET << std::endl;

	char a[] = {'a', 'b', 'c', 'd', 'e', 'f'};

	::iter(a, 6, ::display<char>);
	std::cout << std::endl;

	::iter(a, 6, ::increment<char>);

	::iter(a, 6, ::display<char>);
	std::cout << std::endl;
}

void	testEmpty(void)
{
	std::cout << ABLUE "// Test on empty int ------------------------ // " RESET << std::endl;

	int a[] = {};

	::iter(a, 0, ::display<int>);
	std::cout << std::endl;

	::iter(a, 0, ::increment<int>);

	::iter(a, 0, ::display<int>);
	std::cout << std::endl;
}

int	main(void)
{
	testEmpty();
	testChar();
	testInt();
	testFloat();
	testDouble();
	testString();

	return (0);
}

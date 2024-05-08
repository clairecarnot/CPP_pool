#include "Colors.hpp"
#include "Span.hpp"

int	main(void)
{
	{
		std::cout << ABLUE "// Subject tests ---------------------------------------------- //" RESET << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		std::cout << std::endl;
	}
	{
		std::cout << ABLUE "// Copy, assign. & range tests -------------------------------- //" RESET << std::endl;
		try
		{
			// first instance
			Span sp = Span(10);
			std::cout << sp << std::endl;

			// add a range of values
			std::vector<int> test(10, 2);
			sp.addNumberRange(test);
			std::cout << sp << std::endl;

			// instance from copy constructor
			Span copy(sp);
			std::cout << copy << std::endl;

			// assignment
			Span assign(4);
			assign = sp;
			std::cout << assign << std::endl;

			// add number whereas sp is already full
			sp.addNumber(4);
		}
		catch (std::exception &e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}

		try
		{
			// add a range larger than storage left
			Span othersp(4);
			othersp.addNumber(-1);
			std::vector<int> othertest(2, 3);
			othersp.addNumberRange(othertest);
			std::cout << othersp << std::endl;

			std::vector<int> failingv(5, 1);
			othersp.addNumberRange(failingv);
		}
		catch (std::exception &e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}

		std::cout << std::endl;
	}
	{
		std::cout << ABLUE "// Span calculation tests ------------------------------------- //" RESET << std::endl;
		// empty Span
		Span sp(20000);

		try
		{
			std::cout << sp.shortestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}

		// only 1 number stored
		sp.addNumber(-500);
		try
		{
			std::cout << sp.longestSpan() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}

		// calculate spans
		std::vector<int> v1(5000, 1000);
		std::vector<int> v2(4000, 600);
		std::vector<int> v3(1000, 7);
		try
		{
			sp.addNumberRange(v1);
			sp.addNumberRange(v2);
			sp.addNumberRange(v3);
			std::cout << "Shortest Span: " << LGREEN << sp.shortestSpan() << RESET << std::endl;
			std::cout << "Longuest Span: " << LGREEN << sp.longestSpan() << RESET << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}
	}

	return (0);
}

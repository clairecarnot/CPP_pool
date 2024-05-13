#include "Colors.hpp"
#include "RPN.hpp"

/*
int	main(void)
{
	std::cout << ABLUE  "// Tests from subject -------------------------------- //" RESET << std::endl;

	{
		RPN	rpn;
		std::cout << "./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\"" << std::endl;
		rpn.solve("8 9 * 9 - 9 - 9 - 4 - 1 +");
		std::cout << std::endl;
	}
	{
		RPN	rpn;
		std::cout << "./RPN \"7 7 * 7 -\"" << std::endl;
		rpn.solve("7 7 * 7 -");
		std::cout << std::endl;
	}
	{
		RPN	rpn;
		std::cout << "./RPN \"1 2 * 2 / 2 * 2 4 - +\"" << std::endl;
		rpn.solve("1 2 * 2 / 2 * 2 4 - +");
		std::cout << std::endl;
	}
	{
		RPN	rpn;
		std::cout << "./RPN \"(1 + 1)\"" << std::endl;
		rpn.solve("(1 + 1)");
		std::cout << std::endl;
	}

	std::cout << ABLUE  "// Additional tests ---------------------------------- //" RESET << std::endl;

	{
		// no operations
		RPN	rpn;
		std::cout << "./RPN \"1\"" << std::endl;
		rpn.solve("1");
		std::cout << std::endl;
	}
	{
		// less than 2 numbers
		RPN	rpn;
		std::cout << "./RPN \"1 +\"" << std::endl;
		rpn.solve("1 +");
		std::cout << std::endl;
	}
	{
		// not polish notation
		RPN	rpn;
		std::cout << "./RPN \"1 + 2\"" << std::endl;
		rpn.solve("1 + 2");
		std::cout << std::endl;
	}
	{
		// division by 0
		RPN	rpn;
		std::cout << "./RPN \"1 0 /\"" << std::endl;
		rpn.solve("1 0 /");
		std::cout << std::endl;
	}
	{
		// too large number
		RPN	rpn;
		std::cout << "./RPN \"10 5 4 + -\"" << std::endl;
		rpn.solve("10 5 4 + -");
		std::cout << std::endl;
	}
	{
		// not enough operations
		RPN	rpn;
		std::cout << "./RPN \"1 9 4 -\"" << std::endl;
		rpn.solve("1 9 4 -");
		std::cout << std::endl;
	}
	{
		// not enough numbers
		RPN	rpn;
		std::cout << "./RPN \"8 7 - + /\"" << std::endl;
		rpn.solve("8 7 - + /");
		std::cout << std::endl;
	}
	{
		// OK
		RPN	rpn;
		std::cout << "./RPN \"3 8 4 0 2 / * - +\"" << std::endl;
		rpn.solve("3 8 4 0 2 / * - +");
	}

	return (0);
}
*/

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		RPN	rpn;

		std::string input(argv[1]);
		rpn.solve(input.c_str());
	}
	else
		std::cout << "Error : invalid number of arguments" << std::endl;
	return (0);
}

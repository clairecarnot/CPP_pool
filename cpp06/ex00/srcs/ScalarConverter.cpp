#include "ScalarConverter.hpp"

// CONSTRUCTORS / DESTRUCTORS -------------------------------------------------------------- //

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	*this = src;
}

ScalarConverter::~ScalarConverter(void)
{
}

// OPERATORS ------------------------------------------------------------------------------- //

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &src)
{
	if (this == &src)
		return (*this);
	return (*this);
}

// GETTERS / SETTERS ----------------------------------------------------------------------- //


// FUNCTIONS ------------------------------------------------------------------------------- //


// STATIC ELEMENTS ------------------------------------------------------------------------- //

void	ScalarConverter::convert(std::string const &input)
{
	typedef	bool (*fptrBool)(std::string const &input);
	typedef	void (*fptrVoid)(std::string const &input);

	fptrBool	whichType[5] = {&isLim, &isChar, &isInt, &isFloat, &isDouble};
	fptrVoid	convertAs[5] = {&convertLim, &convertAsChar, &convertAsInt, &convertAsFloat, &convertAsDouble};
	int		index = -1;

	if (!input.length())
	{
		std::cout << "Error : no literal char, int, float or double provided - invalid input." << std::endl;
		return ;
	}

	for (int i = 0; i < 5; i++)
	{
		if (whichType[i](input))
		{
			index = i;
			break ;
		}
	}
	
	if (index != -1)
		(*convertAs[index])(input);
	else
	   std::cout << "Error : no literal char, int, float or double provided - invalid input." << std::endl;
}

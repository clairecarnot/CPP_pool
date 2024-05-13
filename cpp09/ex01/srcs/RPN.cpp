#include "RPN.hpp"

// CONSTRUCTOR / DESTRUCTOR --------------------------------------------------- //

RPN::RPN(void)
{
}

RPN::RPN(RPN const &src)
{
	*this = src;
}

RPN::~RPN(void)
{
}

// OPERATORS ------------------------------------------------------------------ //

RPN	&RPN::operator=(RPN const &src)
{
	if (this != &src)
		return (*this);
	return (*this);
}

// GETTERS / SETTERS ---------------------------------------------------------- //


// FUNCTIONS ------------------------------------------------------------------ //

void	RPN::solve(std::string const &input)
{
	std::string		value;
	std::istringstream	iss(input);
	int			n1;
	int			n2;

	while (iss >> value)
	{
		if (std::isdigit(value[0]) && value.length() == 1)
			this->_pile.push(std::atoi(value.c_str()));
		else if ((value == "+" || value == "-" || value == "/" || value == "*") 
				&& this->_pile.size() > 1)
		{
			n2 = this->_pile.top();
			this->_pile.pop();
			n1 = this->_pile.top();
			this->_pile.pop();

			if (value == "+" && (n1 + n2 <= 2147483647))
				this->_pile.push(n1 + n2);
			else if (value == "-" && (n1 - n2 >= -2147483648))
				this->_pile.push(n1 - n2);
			else if (value == "*" && (n1 * n2 <= 2147483647) 
					&& (n1 * n2 >= -2147483648))
				this->_pile.push(n1 * n2);
			else if (value == "/")
			{
				if (n2 == 0)
				{
					std::cout << "Error : an operation is a division by 0." << std::endl;
					return ;
				}
				else
					this->_pile.push(n1 / n2);
			}
			else
			{
				std::cout << "Error : an operation exceeds int limits." << std::endl;
				return ;
			}
		}
		else
		{
			std::cout << "Error : bad input." << std::endl;
			return ;
		}
	}

	if (this->_pile.size() != 1)
		std::cout << "Error : bad input." << std::endl;
	else
		std::cout << this->_pile.top() << std::endl;
}

// STATIC ELEMENTS ------------------------------------------------------------ //



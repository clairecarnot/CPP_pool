#include "WrongAnimal.hpp"

// CONSTRUCTORS / DESTRUCTORS -------------------------------------------------//

WrongAnimal::WrongAnimal(void) : _type("FiShquirrel")
{
	std::cout << "Default constructor called for \e[33mWrongAnimal\e[0m" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src) : _type(src._type)
{
	std::cout << "Copy constructor called for \e[33mWrongAnimal\e[0m" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Default destructor called for \e[33mWrongAnimal\e[0m" << std::endl;
}

// OPERATORS ------------------------------------------------------------------//

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &src)
{
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

// GETTERS / SETTERS ----------------------------------------------------------// 

std::string	WrongAnimal::getType(void) const
{
	return (this->_type);
}

// FUNCTIONS ------------------------------------------------------------------// 

void	WrongAnimal::makeSound(void) const
{
	std::cout << this->_type << ": " << "\e[33mIiiiiiiik ! blubblub. \e[0m" << std::endl;
}

// STATIC ELEMENTS ------------------------------------------------------------//

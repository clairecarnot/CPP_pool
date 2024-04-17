#include "WrongCat.hpp"

// CONSTRUCTORS / DESTRUCTORS -------------------------------------------------//

WrongCat::WrongCat(void) : WrongAnimal()
{
	this->_type = "WrongCat";
	std::cout << "Default constructor for \e[31mWrongCat\e[0m" << std::endl;
}

WrongCat::WrongCat(WrongCat const &src) : WrongAnimal()
{
	this->_type = src._type;
	std::cout << "Copy constructor for \e[31mWrongCat\e[0m" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "Default destructor for \e[31mWrongCat\e[0m" << std::endl;
}

// OPERATORS ------------------------------------------------------------------//

WrongCat	&WrongCat::operator=(WrongCat const &src)
{
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

// GETTERS / SETTERS ----------------------------------------------------------// 

// FUNCTIONS ------------------------------------------------------------------// 

void	WrongCat::makeSound(void) const
{
	std::cout << this->_type << ": " << "\e[31mMeoooooooooow. Meow ?\e[0m" << std::endl;
}

// STATIC ELEMENTS ------------------------------------------------------------//

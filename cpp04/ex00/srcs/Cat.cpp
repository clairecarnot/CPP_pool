#include "Cat.hpp"

// CONSTRUCTORS / DESTRUCTORS -------------------------------------------------//

Cat::Cat(void) : Animal()
{
	this->_type = "Cat";
	std::cout << "Default constructor for \e[35mCat\e[0m" << std::endl;
}

Cat::Cat(Cat const &src) : Animal()
{
	this->_type = src._type;
	std::cout << "Copy constructor for \e[35mCat\e[0m" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Default destructor for \e[35mCat\e[0m" << std::endl;
}

// OPERATORS ------------------------------------------------------------------//

Cat	&Cat::operator=(Cat const &src)
{
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

// GETTERS / SETTERS ----------------------------------------------------------// 

// FUNCTIONS ------------------------------------------------------------------// 

void	Cat::makeSound(void) const
{
	std::cout << this->_type << ": " << "\e[35mMeoooooooooow. Meow ?\e[0m" << std::endl;
}

// STATIC ELEMENTS ------------------------------------------------------------//

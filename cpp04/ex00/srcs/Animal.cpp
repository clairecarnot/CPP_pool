#include "Animal.hpp"

// CONSTRUCTORS / DESTRUCTORS -------------------------------------------------//

Animal::Animal(void) : _type("FiShquirrel")
{
	std::cout << "Default constructor called for \e[32mAnimal\e[0m" << std::endl;
}

Animal::Animal(Animal const &src) : _type(src._type)
{
	std::cout << "Copy constructor called for \e[32mAnimal\e[0m" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Default destructor called for \e[32mAnimal\e[0m" << std::endl;
}

// OPERATORS ------------------------------------------------------------------//

Animal	&Animal::operator=(Animal const &src)
{
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

// GETTERS / SETTERS ----------------------------------------------------------// 

std::string	Animal::getType(void) const
{
	return (this->_type);
}

// FUNCTIONS ------------------------------------------------------------------// 

void	Animal::makeSound(void) const
{
	std::cout << this->_type << ": " << "\e[32mIiiiiiiik ! blubblub. \e[0m" << std::endl;
}

// STATIC ELEMENTS ------------------------------------------------------------//

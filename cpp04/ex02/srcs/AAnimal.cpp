#include "AAnimal.hpp"

// CONSTRUCTORS / DESTRUCTORS -------------------------------------------------//

AAnimal::AAnimal(void) : _type("FiShquirrel")
{
	std::cout << "Default constructor called for \e[32mAnimal\e[0m" << std::endl;
}

AAnimal::AAnimal(AAnimal const &src) : _type(src._type)
{
	std::cout << "Copy constructor called for \e[32mAnimal\e[0m" << std::endl;
}

AAnimal::~AAnimal(void)
{
	std::cout << "Default destructor called for \e[32mAnimal\e[0m" << std::endl;
}

// OPERATORS ------------------------------------------------------------------//

AAnimal	&AAnimal::operator=(AAnimal const &src)
{
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

// GETTERS / SETTERS ----------------------------------------------------------// 

std::string	AAnimal::getType(void) const
{
	return (this->_type);
}

// FUNCTIONS ------------------------------------------------------------------// 

void	AAnimal::makeSound(void) const
{
	std::cout << this->_type << ": " << "\e[32mIiiiiiiik ! blubblub. \e[0m" << std::endl;
}

// STATIC ELEMENTS ------------------------------------------------------------//

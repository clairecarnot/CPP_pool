#include "Dog.hpp"

// CONSTRUCTORS / DESTRUCTORS -------------------------------------------------//

Dog::Dog(void) : Animal()
{
	this->_type = "Dog";
	std::cout << "Default constructor for \e[36mDog\e[0m" << std::endl;
}

Dog::Dog(Dog const &src) : Animal()
{
	this->_type = src._type;
	std::cout << "Copy constructor for \e[36mDog\e[0m" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Default destructor for \e[36mDog\e[0m" << std::endl;
}

// OPERATORS ------------------------------------------------------------------//

Dog	&Dog::operator=(Dog const &src)
{
	if (this != &src)
		this->_type = src._type;
	return (*this);
}

// GETTERS / SETTERS ----------------------------------------------------------// 

// FUNCTIONS ------------------------------------------------------------------// 

void	Dog::makeSound(void) const
{
	std::cout << this->_type << ": " << "\e[36mWOUF. WOUF. WOUFWOUF !\e[0m" << std::endl;
}

// STATIC ELEMENTS ------------------------------------------------------------//

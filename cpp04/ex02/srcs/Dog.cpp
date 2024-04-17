#include "Dog.hpp"

// CONSTRUCTORS / DESTRUCTORS -------------------------------------------------//

Dog::Dog(void) : AAnimal(), _brain(new Brain())
{
	this->_type = "Dog";
	std::cout << "Default constructor for \e[36mDog\e[0m" << std::endl;
}

Dog::Dog(Dog const &src) : AAnimal(), _brain(new Brain (*src._brain))
{
	this->_type = src._type;
	std::cout << "Copy constructor for \e[36mDog\e[0m" << std::endl;
}

Dog::~Dog(void)
{
	delete this->_brain;
	std::cout << "Default destructor for \e[36mDog\e[0m" << std::endl;
}

// OPERATORS ------------------------------------------------------------------//

Dog	&Dog::operator=(Dog const &src)
{
	if (this != &src)
	{
		this->_type = src._type;
		delete this->_brain;
		this->_brain = new Brain(*src._brain);
	}
	return (*this);
}

// GETTERS / SETTERS ----------------------------------------------------------// 

// FUNCTIONS ------------------------------------------------------------------// 

void	Dog::makeSound(void) const
{
	std::cout << this->_type << ": " << "\e[36mWOUF. WOUF. WOUFWOUF !\e[0m" << std::endl;
}

Brain	*Dog::getBrain(void) const
{
	return (this->_brain);
}

// STATIC ELEMENTS ------------------------------------------------------------//

#include "Cat.hpp"

// CONSTRUCTORS / DESTRUCTORS -------------------------------------------------//

Cat::Cat(void) : AAnimal(), _brain(new Brain())
{
	this->_type = "Cat";
	std::cout << "Default constructor for \e[35mCat\e[0m" << std::endl;
}

Cat::Cat(Cat const &src) : AAnimal(), _brain(new Brain(*src._brain))
{
	this->_type = src._type;
	std::cout << "Copy constructor for \e[35mCat\e[0m" << std::endl;
}

Cat::~Cat(void)
{
	delete this->_brain;
	std::cout << "Default destructor for \e[35mCat\e[0m" << std::endl;
}

// OPERATORS ------------------------------------------------------------------//

Cat	&Cat::operator=(Cat const &src)
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

void	Cat::makeSound(void) const
{
	std::cout << this->_type << ": " << "\e[35mMeoooooooooow. Meow ?\e[0m" << std::endl;
}

Brain	*Cat::getBrain(void) const
{
	return (this->_brain);
}

// STATIC ELEMENTS ------------------------------------------------------------//

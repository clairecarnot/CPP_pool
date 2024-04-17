#include "Ice.hpp"

// CONSTRUCTORS / DESTRUCTORS -------------------------------------------------//

Ice::Ice(void) : AMateria("ice")
{
}

Ice::Ice(Ice const &src) : AMateria(src._type)
{
}

Ice::~Ice(void)
{
}

// OPERATORS ------------------------------------------------------------------//

Ice	&Ice::operator=(Ice const &src)
{
	(void)src;
	return (*this);
}

// GETTERS / SETTERS ----------------------------------------------------------// 


// FUNCTIONS ------------------------------------------------------------------// 

AMateria	*Ice::clone(void) const
{
	AMateria *matClone = new Ice();
	return (matClone);
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

// STATIC ELEMENTS ------------------------------------------------------------//

#include "Cure.hpp"

// CONSTRUCTORS / DESTRUCTORS -------------------------------------------------//

Cure::Cure(void) : AMateria("cure")
{
}

Cure::Cure(Cure const &src) : AMateria(src._type)
{
}

Cure::~Cure(void)
{
}

// OPERATORS ------------------------------------------------------------------//

Cure	&Cure::operator=(Cure const &src)
{
	(void)src;
	return (*this);
}

// GETTERS / SETTERS ----------------------------------------------------------// 


// FUNCTIONS ------------------------------------------------------------------// 

AMateria	*Cure::clone(void) const
{
	AMateria *matClone = new Cure();
	return (matClone);
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

// STATIC ELEMENTS ------------------------------------------------------------//

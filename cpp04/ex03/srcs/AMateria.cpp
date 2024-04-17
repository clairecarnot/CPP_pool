#include "AMateria.hpp"

// CONSTRUCTORS / DESTRUCTORS -------------------------------------------------//

AMateria::AMateria(std::string const &type) : _type(type)
{
}

AMateria::AMateria(AMateria const &src) : _type(src._type)
{
}

AMateria::~AMateria(void)
{
}

// OPERATORS ------------------------------------------------------------------//

AMateria	&AMateria::operator=(AMateria const &src)
{
	(void)src;
	return (*this);
}

// GETTERS / SETTERS ----------------------------------------------------------// 

std::string const	&AMateria::getType(void) const
{
	return (this->_type);
}

// FUNCTIONS ------------------------------------------------------------------// 

void	AMateria::use(ICharacter &target)
{
	(void) target;
}

// STATIC ELEMENTS ------------------------------------------------------------//

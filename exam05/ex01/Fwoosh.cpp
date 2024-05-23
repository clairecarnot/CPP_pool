#include "Fwoosh.hpp"

// Constructors / Destructor ------------------------------------------------------ //

Fwoosh::Fwoosh(void) : ASpell("Fwoosh", "fwooshed")
{
}

Fwoosh::Fwoosh(Fwoosh const &src) : ASpell(src.getName(), src.getEffects())
{
	*this = src;
}

Fwoosh::~Fwoosh(void)
{
}

// Operators ---------------------------------------------------------------------- //

Fwoosh	&Fwoosh::operator=(Fwoosh const &src)
{
	if (this != &src)
	{
		this->_name = src.getName();
		this->_effects = src.getEffects();
	}
	return (*this);
}

// Getters / setters -------------------------------------------------------------- //


// Fonctions ---------------------------------------------------------------------- //

ASpell	*Fwoosh::clone(void) const
{
	return (new Fwoosh());
}


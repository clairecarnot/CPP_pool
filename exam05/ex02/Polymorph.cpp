#include "Polymorph.hpp"

// Constructors / Destructor ------------------------------------------------------ //

Polymorph::Polymorph(void) : ASpell("Polymorph", "turned into a critter")
{
}

Polymorph::Polymorph(Polymorph const &src) : ASpell(src.getName(), src.getEffects())
{
	*this = src;
}

Polymorph::~Polymorph(void)
{
}

// Operators ---------------------------------------------------------------------- //

Polymorph	&Polymorph::operator=(Polymorph const &src)
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

ASpell	*Polymorph::clone(void) const
{
	return (new Polymorph());
}


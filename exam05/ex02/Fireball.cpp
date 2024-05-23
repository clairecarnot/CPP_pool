#include "Fireball.hpp"

// Constructors / Destructor ------------------------------------------------------ //

Fireball::Fireball(void) : ASpell("Fireball", "burnt to a crisp")
{
}

Fireball::Fireball(Fireball const &src) : ASpell(src.getName(), src.getEffects())
{
	*this = src;
}

Fireball::~Fireball(void)
{
}

// Operators ---------------------------------------------------------------------- //

Fireball	&Fireball::operator=(Fireball const &src)
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

ASpell	*Fireball::clone(void) const
{
	return (new Fireball());
}


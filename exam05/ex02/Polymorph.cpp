#include "Polymorph.hpp"

// -------------------------------------------------------- //

Polymorph::Polymorph() : ASpell("Polymorph", "turned into a critter")
{
}

Polymorph::Polymorph(Polymorph const &src) : ASpell(src.getName(), src.getEffects())
{
}

Polymorph::~Polymorph()
{
}

// -------------------------------------------------------- //

Polymorph	&Polymorph::operator=(Polymorph const &src)
{
	if (this != &src)
	{
		return (*this);
	}
	return (*this);
}

// -------------------------------------------------------- //

ASpell	*Polymorph::clone() const
{
	return (new Polymorph());
}

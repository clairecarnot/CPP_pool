#include "Fwoosh.hpp"

// -------------------------------------------------------- //

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed")
{
}

Fwoosh::Fwoosh(Fwoosh const &src) : ASpell(src.getName(), src.getEffects())
{
}

Fwoosh::~Fwoosh()
{
}

// -------------------------------------------------------- //

Fwoosh	&Fwoosh::operator=(Fwoosh const &src)
{
	if (this != &src)
	{
		return (*this);
	}
	return (*this);
}

// -------------------------------------------------------- //

ASpell	*Fwoosh::clone() const
{
	return (new Fwoosh());
}

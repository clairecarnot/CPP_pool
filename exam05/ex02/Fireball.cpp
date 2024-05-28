#include "Fireball.hpp"

// -------------------------------------------------------- //

Fireball::Fireball() : ASpell("Fireball", "burnt to a crisp")
{
}

Fireball::Fireball(Fireball const &src) : ASpell(src.getName(), src.getEffects())
{
}

Fireball::~Fireball()
{
}

// -------------------------------------------------------- //

Fireball	&Fireball::operator=(Fireball const &src)
{
	if (this != &src)
	{
		return (*this);
	}
	return (*this);
}

// -------------------------------------------------------- //

ASpell	*Fireball::clone() const
{
	return (new Fireball());
}

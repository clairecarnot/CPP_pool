#include "ASpell.hpp"

// Constructors / Destructor ------------------------------------------------------ //

ASpell::ASpell(std::string const &name, std::string const &effects) : _name(name), _effects(effects)
{
}

ASpell::ASpell(ASpell const &src)
{
	*this = src;
}

ASpell::~ASpell(void)
{
}

// Operators ---------------------------------------------------------------------- //

ASpell	&ASpell::operator=(ASpell const &src)
{
	if (this != &src)
	{
		this->_name = src.getName();
		this->_effects = src.getEffects();
	}
	return (*this);
}

// Getters / setters -------------------------------------------------------------- //

std::string const	&ASpell::getName(void) const
{
	return (this->_name);
}

std::string const	&ASpell::getEffects(void) const
{
	return (this->_effects);
}

// Fonctions ---------------------------------------------------------------------- //

void	ASpell::launch(ATarget const &target) const
{
	target.getHitBySpell(*this);
}

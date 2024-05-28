#include "ASpell.hpp"

// ------------------------------------------------------- //

ASpell::ASpell()
{
}

ASpell::ASpell(std::string const &name, std::string const &effects) : _name(name), _effects(effects)
{
}

ASpell::ASpell(ASpell const &src)
{
	*this = src;
}

ASpell::~ASpell()
{
}

// ------------------------------------------------------- //

ASpell	&ASpell::operator=(ASpell const &src)
{
	if (this != &src)
	{
		this->_name = src.getName();
		this->_effects = src.getEffects();
	}
	return (*this);
}

// ------------------------------------------------------- //

std::string const	&ASpell::getName() const
{
	return (this->_name);
}

std::string const	&ASpell::getEffects() const
{
	return (this->_effects);
}

// ------------------------------------------------------- //

void	ASpell::launch(ATarget const &target) const
{
	target.getHitBySpell(*this);
}

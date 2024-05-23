#include "ATarget.hpp"

// Constructors / Destructor ------------------------------------------------------ //

ATarget::ATarget(void)
{
}

ATarget::ATarget(std::string const &type) : _type(type)
{
}

ATarget::ATarget(ATarget const &src)
{
	*this = src;
}

ATarget::~ATarget(void)
{
}

// Operators ---------------------------------------------------------------------- //

ATarget	&ATarget::operator=(ATarget const &src)
{
	if (this != &src)
	{
		this->_type = src.getType();
	}
	return (*this);
}

// Getters / setters -------------------------------------------------------------- //

std::string const	&ATarget::getType(void) const
{
	return (this->_type);
}

// Fonctions ---------------------------------------------------------------------- //

void	ATarget::getHitBySpell(ASpell const &spell) const
{
	std::cout << this->getType() << " has been " << spell.getEffects() << "!" << std::endl;
}

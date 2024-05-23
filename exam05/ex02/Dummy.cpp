#include "Dummy.hpp"

// Constructors / Destructor ------------------------------------------------------ //

Dummy::Dummy(void) : ATarget("Target Practice Dummy")
{
}

Dummy::Dummy(Dummy const &src)
{
	*this = src;
}

Dummy::~Dummy(void)
{
}

// Operators ---------------------------------------------------------------------- //

Dummy	&Dummy::operator=(Dummy const &src)
{
	if (this != &src)
	{
		this->_type = src.getType();
	}
	return (*this);
}

// Getters / setters -------------------------------------------------------------- //


// Fonctions ---------------------------------------------------------------------- //

ATarget	*Dummy::clone(void) const
{
	return (new Dummy());
}

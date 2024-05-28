#include "Dummy.hpp"

// ------------------------------------------------------- //

Dummy::Dummy() : ATarget("Target Practice Dummy")
{
}

Dummy::Dummy(Dummy const &src) : ATarget(src.getType())
{
}

Dummy::~Dummy()
{
}

// ------------------------------------------------------- //

Dummy	&Dummy::operator=(Dummy const &src)
{
	if (this != &src)
	{
		return (*this);
	}
	return (*this);
}

// ------------------------------------------------------- //

ATarget	*Dummy::clone() const
{
	return (new Dummy());
}


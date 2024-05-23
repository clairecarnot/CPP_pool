#include "BrickWall.hpp"

// Constructors / Destructor ------------------------------------------------------ //

BrickWall::BrickWall(void) : ATarget("Inconspicuous Red-brick Wall")
{
}

BrickWall::BrickWall(BrickWall const &src)
{
	*this = src;
}

BrickWall::~BrickWall(void)
{
}

// Operators ---------------------------------------------------------------------- //

BrickWall	&BrickWall::operator=(BrickWall const &src)
{
	if (this != &src)
	{
		this->_type = src.getType();
	}
	return (*this);
}

// Getters / setters -------------------------------------------------------------- //


// Fonctions ---------------------------------------------------------------------- //

ATarget	*BrickWall::clone(void) const
{
	return (new BrickWall());
}

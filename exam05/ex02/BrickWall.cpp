#include "BrickWall.hpp"

// ------------------------------------------------------- //

BrickWall::BrickWall() : ATarget("Inconspicuous Red-brick Wall")
{
}

BrickWall::BrickWall(BrickWall const &src) : ATarget(src.getType())
{
}

BrickWall::~BrickWall()
{
}

// ------------------------------------------------------- //

BrickWall	&BrickWall::operator=(BrickWall const &src)
{
	if (this != &src)
	{
		return (*this);
	}
	return (*this);
}

// ------------------------------------------------------- //

ATarget	*BrickWall::clone() const
{
	return (new BrickWall());
}


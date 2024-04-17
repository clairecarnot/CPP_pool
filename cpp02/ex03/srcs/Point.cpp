# include "Point.hpp"

/* CONSTRUCTORS / DESTRUCTORS -----------------------------------------------*/

Point::Point(void) :  _x(0), _y(0)
{
}

Point::Point(Point const &pointToCopy) : _x(pointToCopy.getX()), _y(pointToCopy.getY())
{
}

Point::Point(float const x, float const y) : _x(x), _y(y)
{
}

Point::~Point(void)
{
}

/* OPERATORS ----------------------------------------------------------------*/

// operator= : cannot change const x and y

Point	&Point::operator=(Point const &pointToAssign)
{
	(void) pointToAssign;
	return (*this);
}

/* FUNCTIONS ----------------------------------------------------------------*/

Fixed const	&Point::getX(void) const
{
	return (this->_x);
}

Fixed const	&Point::getY(void) const
{
	return (this->_y);
}

/* STATIC VARS AND FUNCTIONS ------------------------------------------------*/

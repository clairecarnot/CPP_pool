#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	w1;
	Fixed	w2;

	w1 = ( a.getX() * (c.getY() - a.getY()) + (point.getY() - a.getY()) * (c.getX() - a.getX()) - point.getX() * (c.getY() - a.getY()) ) / ( (b.getY() - a.getY()) * (c.getX() - a.getX()) - (b.getX() - a.getX()) * (c.getY() - a.getY()) );

	w2 = ( point.getY() - a.getY() - w1 * (b.getY() - a.getY()) ) / ( c.getY() - a.getY() );

	if ( (w1.getRawBits() > 0) && ( w2.getRawBits() > 0 )
			&& (w1 + w2 < 1) )
		return (true);
	else
		return (false);
}

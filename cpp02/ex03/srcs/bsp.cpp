#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	zero(0.0f);
	Fixed	w1;
	Fixed	w2;
	Fixed	denominator = ( (b.getY() - a.getY()) * (c.getX() - a.getX()) - (b.getX() - a.getX()) * (c.getY() - a.getY()) );

	if ( (denominator != zero) && (c.getY() != a.getY()) )
	{
		w1 = ( a.getX() * (c.getY() - a.getY()) + (point.getY() - a.getY()) * (c.getX() - a.getX()) - point.getX() * (c.getY() - a.getY()) ) / ( (b.getY() - a.getY()) * (c.getX() - a.getX()) - (b.getX() - a.getX()) * (c.getY() - a.getY()) );

		w2 = ( point.getY() - a.getY() - w1 * (b.getY() - a.getY()) ) / ( c.getY() - a.getY() );
	}
	else
	{
		denominator = ( (b.getY() - a.getY()) * (c.getX() - a.getX()) - (b.getX() - a.getX()) * (c.getY() - a.getY()) );
		if ( (denominator != zero) && (c.getX() != a.getX()) )
		{
			w1 = ( (point.getY() - a.getY()) * (c.getX() - a.getX()) - (point.getX() - a.getX()) * (c.getY() - a.getY()) ) / ( (b.getY() - a.getY()) * (c.getX() - a.getX()) - (b.getX() - a.getX()) * (c.getY() - a.getY()) );
			w2 = ( point.getX() - a.getX() - w1 * (b.getX() - a.getX()) ) / (c.getX() - a.getX());
		}
		else
		{
			std::cout << "Case of division by 0 not handled." << std::endl;
			return (false);
		}
	}
	if ( (w1.getRawBits() > 0) && ( w2.getRawBits() > 0 )
			&& (w1 + w2 < 1) )
		return (true);
	else
		return (false);
}

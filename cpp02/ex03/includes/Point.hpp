#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class	Point
{
	public:
		Point(void);
		Point(Point const &pointToCopy);
		Point(float const x, float const y);
		~Point(void);
		
		Point	&operator=(Point const &pointToAssign);

		Fixed const	&getX(void) const;
		Fixed const	&getY(void) const;

	private:
		Fixed const	_x;
		Fixed const	_y;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif

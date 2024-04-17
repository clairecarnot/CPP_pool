#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
	public:
		Fixed(void);
		Fixed(int const n);
		Fixed(float const f);
		Fixed(Fixed const &fixedToCopy);
		~Fixed(void);

		Fixed	&operator=(Fixed const &fixedToAssign);

		int	getRawBits(void) const;
		void	setRawBits(int const &raw);
		float	toFloat(void) const;
		int	toInt(void) const;

	private:
		int			_value;
		static int const	_fractionBits;

};

std::ostream	&operator<<(std::ostream &flux, Fixed const &fixedToPrint);

#endif

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed
{
	public:
		Fixed(void);
		Fixed(Fixed &fixedToCopy);
		~Fixed(void);

		Fixed	&operator=(Fixed const &fixedToAssign);

		int	getRawBits(void) const;
		void	setRawBits(int const &raw);

	private:
		int			_value;
		static int const	_fractionBits;

};

#endif

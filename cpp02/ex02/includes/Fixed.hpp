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

		bool	operator>(Fixed const &fixedObj) const;
		bool	operator<(Fixed const &fixedObj) const;
		bool	operator>=(Fixed const &fixedObj) const;
		bool	operator<=(Fixed const &fixedObj) const;
		bool	operator==(Fixed const &fixedObj) const;
		bool	operator!=(Fixed const &fixedObj) const;

		Fixed	operator+(Fixed const &fixedObj) const;
		Fixed	operator-(Fixed const &fixedObj) const;
		Fixed	operator*(Fixed const &fixedObj) const;
		Fixed	operator/(Fixed const &fixedObj) const;

		Fixed	&operator++(void);
		Fixed	&operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);

		int	getRawBits(void) const;
		void	setRawBits(int const &raw);
		float	toFloat(void) const;
		int	toInt(void) const;

		static Fixed	&min(Fixed &obj1, Fixed &obj2);
		static Fixed	&max(Fixed &obj1, Fixed &obj2);
		static Fixed const	&min(Fixed const &obj1, Fixed const &obj2);
		static Fixed const	&max(Fixed const &obj1, Fixed const &obj2);

	private:
		int			_value;
		static int const	_fractionBits;

};

std::ostream	&operator<<(std::ostream &flux, Fixed const &fixedToPrint);

#endif

#include "Fixed.hpp"

/* CONSTRUCTORS / DESTRUCTORS -----------------------------------------------*/

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &fixedToCopy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixedToCopy;
}

Fixed::Fixed(int const n) : _value(n << this->_fractionBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const f) : _value(roundf(f * (1 << this->_fractionBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

/* OPERATORS ----------------------------------------------------------------*/

Fixed	&Fixed::operator=(Fixed const &fixedToAssign)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixedToAssign)
		this->_value = fixedToAssign.getRawBits();
	return (*this);
}

std::ostream	&operator<<(std::ostream &flux, Fixed const &fixedToPrint)
{
	flux << fixedToPrint.toFloat();
	return (flux);
}

/* FUNCTIONS ----------------------------------------------------------------*/

int	Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const &raw)
{
	this->_value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float) this->_value / (1 << _fractionBits));
}

int	Fixed::toInt(void) const
{
	return (this->_value >> _fractionBits);
}

/* STATIC -------------------------------------------------------------------*/

int const	Fixed::_fractionBits = 8;

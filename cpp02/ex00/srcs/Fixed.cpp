#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed &fixedToCopy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixedToCopy;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(Fixed const &fixedToAssign)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixedToAssign)
	{
		this->_value = fixedToAssign.getRawBits();
	}
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const &raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

int const	Fixed::_fractionBits = 8;

#include "Fixed.hpp"

/* CONSTRUCTORS / DESTRUCTORS -----------------------------------------------*/

Fixed::Fixed(void) : _value(0)
{
}

Fixed::Fixed(Fixed const &fixedToCopy)
{
	*this = fixedToCopy;
}

Fixed::Fixed(int const n) : _value(n << this->_fractionBits)
{
}

Fixed::Fixed(float const f) : _value(roundf(f * (1 << this->_fractionBits)))
{
}

Fixed::~Fixed(void)
{
}

/* OPERATORS ----------------------------------------------------------------*/

Fixed	&Fixed::operator=(Fixed const &fixedToAssign)
{
	if (this != &fixedToAssign)
		this->_value = fixedToAssign.getRawBits();
	return (*this);
}

std::ostream	&operator<<(std::ostream &flux, Fixed const &fixedToPrint)
{
	flux << fixedToPrint.toFloat();
	return (flux);
}

bool	Fixed::operator>(Fixed const &fixedObj) const
{
	return (this->getRawBits() > fixedObj.getRawBits());
}

bool	Fixed::operator<(Fixed const &fixedObj) const
{
	return (this->getRawBits() < fixedObj.getRawBits());
}

bool	Fixed::operator>=(Fixed const &fixedObj) const
{
	return (this->getRawBits() >= fixedObj.getRawBits());
}

bool	Fixed::operator<=(Fixed const &fixedObj) const
{
	return (this->getRawBits() <= fixedObj.getRawBits());
}

bool	Fixed::operator==(Fixed const &fixedObj) const
{
	return (this->getRawBits() == fixedObj.getRawBits());
}

bool	Fixed::operator!=(Fixed const &fixedObj) const
{
	return (this->getRawBits() != fixedObj.getRawBits());
}

Fixed	Fixed::operator+(Fixed const &fixedObj) const
{
	Fixed	result;

	result.setRawBits(this->getRawBits() + fixedObj.getRawBits());
	return (result);
}

Fixed	Fixed::operator-(Fixed const &fixedObj) const
{
	Fixed	result;

	result.setRawBits(this->getRawBits() - fixedObj.getRawBits());
	return (result);
}

	/* Operator *
	Fixed	result;

	for (int i = 0; i * (1 << _fractionBits) < this->getRawBits(); i++)
		result.setRawBits(result.getRawBits() + fixedObj.getRawBits());
	return (result);
	*/

Fixed	Fixed::operator*(Fixed const &fixedObj) const
{
	Fixed result;

	result.setRawBits((this->getRawBits() * fixedObj.getRawBits()) / (1 << _fractionBits));
	return (result);
}

	/* Operator /
	Fixed result;

	int n = roundf((this->getRawBits() * (1 << this->_fractionBits)) / (fixedObj.getRawBits()));
	result.setRawBits(n);
	 */

Fixed	Fixed::operator/(Fixed const &fixedObj) const
{
	Fixed result((float) this->getRawBits() / fixedObj.getRawBits());
	return (result);
}

	/* Pre increment ++
	To actually increment by +1:
	this->setRawBits(this->getRawBits() + (1 << this->_fractionBits));
	*/

Fixed	&Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	&Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);

	this->setRawBits(this->getRawBits() + 1);
	return (tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);

	this->setRawBits(this->getRawBits() - 1);
	return (tmp);
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

/* STATIC VARS AND FUNCTIONS ------------------------------------------------*/

int const	Fixed::_fractionBits = 8;

Fixed	&Fixed::min(Fixed &obj1, Fixed &obj2) 
{
	if (obj1 <= obj2)
		return (obj1);
	else
		return (obj2);
}

Fixed	&Fixed::max(Fixed &obj1, Fixed &obj2) 
{
	if (obj1 >= obj2)
		return (obj1);
	else
		return (obj2);
}

Fixed const	&Fixed::min(Fixed const &obj1, Fixed const &obj2) 
{
	if (obj1 <= obj2)
		return (obj1);
	else
		return (obj2);
}

Fixed const	&Fixed::max(Fixed const &obj1, Fixed const &obj2) 
{
	if (obj1 >= obj2)
		return (obj1);
	else
		return (obj2);
}

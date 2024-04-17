#include "Fixed.hpp"

int	main(void)
{
	/*
	Fixed		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
	*/

	Fixed	a(2);
	Fixed	b(5.05f);
//	Fixed	a(-2);
//	Fixed	b(-5.05f);
//	Fixed	a(2);
//	Fixed	b(-5.05f);

	std::cout << "INITIAL VALUES --------------------------------------------" << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;

	std::cout << "COMPARISONS -----------------------------------------------" << std::endl;
	std::cout << "a > b : " << (a > b) << std::endl;
	std::cout << "a < b : " << (a < b) << std::endl;
	std::cout << "a >= b : " << (a >= b) << std::endl;
	std::cout << "a <= b : " << (a <= b) << std::endl;
	std::cout << "a == b : " << (a == b) << std::endl;
	std::cout << "a != b : " << (a != b) << std::endl;

	std::cout << "OPERATIONS ------------------------------------------------" << std::endl;
	std::cout << "a + b = " << (a + b) << std::endl;
	std::cout << "a - b = " << (a - b) << std::endl;
	std::cout << "a * b = " << (a * b) << std::endl;
	std::cout << "a / b = " << (a / b) << std::endl;

	std::cout << "PRE INCREMENTATIONS ---------------------------------------" << std::endl;
	std::cout << "++a = " << (++a) << std::endl;
	std::cout << "++b = " << (++b) << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	--a;
	--b;
	std::cout << "--a = " << (--a) << std::endl;
	std::cout << "--b = " << (--b) << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	++a;
	++b;

	std::cout << "POST INCREMENTATIONS --------------------------------------" << std::endl;
	std::cout << "a++ = " << (a++) << std::endl;
	std::cout << "b++ = " << (b++) << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	a--;
	b--;
	std::cout << "a-- = " << (a--) << std::endl;
	std::cout << "b-- = " << (b--) << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	a++;
	b++;

	std::cout << "MIN / MAX -------------------------------------------------" << std::endl;
	std::cout << "min(a, b) = " << Fixed::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << Fixed::max(a, b) << std::endl;

	return 0;
}

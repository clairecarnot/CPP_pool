#include "Colors.hpp"
#include "whatever.hpp"

void	testChar(void)
{
	std::cout << ABLUE "// Test Char ------------------------------------- //" RESET << std::endl;

	char a = 'm';
	char b = 'K';

	std::cout << "Before swap : ";
	std::cout << "a = " << a << ", b = " << b << std::endl;

	::swap( a, b );
	std::cout << "After swap : ";
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::cout << std::endl;

}

void	testDouble(void)
{
	std::cout << ABLUE "// Test Double ----------------------------------- //" RESET << std::endl;

	double a = -4.12;
	double b = 1.5;

	std::cout << "Before swap : ";
	std::cout << "a = " << a << ", b = " << b << std::endl;

	::swap( a, b );
	std::cout << "After swap : ";
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::cout << std::endl;

}

void	testFloat(void)
{
	std::cout << ABLUE "// Test Float ------------------------------------ //" RESET << std::endl;

	float a = -5.33f;
	float b = -8.4f;

	std::cout << "Before swap : ";
	std::cout << "a = " << a << ", b = " << b << std::endl;

	::swap( a, b );
	std::cout << "After swap : ";
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::cout << std::endl;

}

void	testSubject(void)
{
	std::cout << ABLUE "// Tests from subject ---------------------------- //" RESET << std::endl;

	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	std::cout << std::endl;

}

int	main(void)
{
	testSubject();
	testFloat();
	testDouble();
	testChar();

	return (0);
}

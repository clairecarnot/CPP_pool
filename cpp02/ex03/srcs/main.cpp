#include "Point.hpp"

// ------------------------ 1 -------------------------------
// Inside
void	example1(void)
{
	Point const	a(1, 1);
	Point const	b(7, 0);
	Point const	c(0, 5);
	Point const	point(2, 3);
	std::cout << bsp(a, b, c, point) << std::endl;
}

// Outside
void	example2(void)
{
	Point const	a(1, 1);
	Point const	b(7, 0);
	Point const	c(0, 5);
	Point const	point(-2, -3);
	std::cout << bsp(a, b, c, point) << std::endl;
}

// Border
void	example3(void)
{
	Point const	a(1, 1);
	Point const	b(7, 0);
	Point const	c(0, 5);
	Point const	point(1, 1);
	std::cout << bsp(a, b, c, point) << std::endl;
}


// ------------------------ 2 -------------------------------
// Inside 
void	example4(void)
{
	Point const	a(-1.5f, -0.5f);
	Point const	b(1.5f, 3.5f);
	Point const	c(2.5f, -2.5f);
	Point const	point(0, 0);
	std::cout << bsp(a, b, c, point) << std::endl;
}

// Outside
void	example5(void)
{
	Point const	a(-1.5f, -0.5f);
	Point const	b(1.5f, 3.5f);
	Point const	c(2.5f, -2.5f);
	Point const	point(2, 2);
	std::cout << bsp(a, b, c, point) << std::endl;
}

// Border
void	example6(void)
{
	Point const	a(-1.5f, -0.5f);
	Point const	b(1.5f, 3.5f);
	Point const	c(2.5f, -2.5f);
	Point const	point(0, -1.5f);
	std::cout << bsp(a, b, c, point) << std::endl;
}

// Cas div /0
void	example7(void)
{
	Point const	a(0, 0);
	Point const	b(0, -1);
	Point const	c(-1, 0);
	Point const	point(-0.4f, -0.4f);
	std::cout << bsp(a, b, c, point) << std::endl;
}

// Cas div /0
void	example8(void)
{
	Point const	a(0, 0);
	Point const	b(4, 0);
	Point const	c(0, 3);
	Point const	point(1, 1);
	std::cout << bsp(a, b, c, point) << std::endl;
}

int	main(void)
{

	std::cout << "example 1" << std::endl;
	example1();

	std::cout << "example 2" << std::endl;
	example2();

	std::cout << "example 3" << std::endl;
	example3();

	std::cout << "example 4" << std::endl;
	example4();

	std::cout << "example 5" << std::endl;
	example5();

	std::cout << "example 6" << std::endl;
	example6();

	std::cout << "example 7" << std::endl;
	example7();

	std::cout << "example 8" << std::endl;
	example8();

	return (0);
}


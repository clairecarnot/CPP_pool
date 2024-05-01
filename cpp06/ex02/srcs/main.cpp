#include "Colors.hpp"
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	std::srand(std::time(0));
	int randnum = std::rand() % 3;

	switch (randnum)
	{
		case 0:
			std::cout << LGREEN "A" RESET << " generated" << std::endl;
			return (new A);
		case 1:
			std::cout << LGREEN "B" RESET << " generated" << std::endl;
			return (new B);
		case 2:
			std::cout << LGREEN "C" RESET << " generated" << std::endl;
			return (new C);
	}
	return (NULL);
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << LGREEN "A" RESET;
	else if (dynamic_cast<B*>(p))
		std::cout << LGREEN "B" RESET;
	else if (dynamic_cast<C*>(p))
		std::cout << LGREEN "C" RESET;
	else
		std::cout << "Error - unknown." << std::endl;
}

void	identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		std::cout << LGREEN "A" RESET;
		(void) a;
	}
	catch (std::exception &e) {}

	try
	{
		B &b = dynamic_cast<B&>(p);
		std::cout << LGREEN "B" RESET;
		(void) b;
	}
	catch (std::exception &e) {}

	try
	{
		C &c = dynamic_cast<C&>(p);
		std::cout << LGREEN "C" RESET;
		(void) c;
	}
	catch (std::exception &e) {}
}

int	main(void)
{
	// Generate randomly
	Base	*p = generate();

	// Pointer
	identify(p);
	std::cout << " pointer identified" << std::endl;

	// Reference
	identify(*p);
	std::cout << " reference identified" << std::endl;

	delete p;

	return (0);
}

#include "Harl.hpp"

int	main(void)
{
	Harl harlMan;

	harlMan.complain("DEBUG");
	std::cout << std::endl;

	harlMan.complain("INFO");
	std::cout << std::endl;

	harlMan.complain("WARNING");
	std::cout << std::endl;

	harlMan.complain("ERROR");
	std::cout << std::endl;

	harlMan.complain("OTHER");

	return (0);
}

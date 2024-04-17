#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl harlMan;

	if (argc != 2)
	{
		std::cout << "Invalid number of arguments." << std::endl
			<< "Expected format: ./program <LEVEL>" << std::endl
			<< "Levels are: 'DEBUG', 'INFO', 'WARNING', 'ERROR'" << std::endl;
		return (1);
	}
	harlMan.complain(argv[1]);
	return (0);
}

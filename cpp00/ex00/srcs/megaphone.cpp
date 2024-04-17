#include <ctype.h>
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::string string(argv[i]);
			for (size_t j = 0; j < string.size(); j++)
				std::cout << (char) toupper(string[j]);
		}
		std::cout << std::endl;
	}
	return 0;
}

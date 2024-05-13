#include "Colors.hpp"
#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		try
		{
			BitcoinExchange	btc;

			std::string	filename(argv[1]);
			std::ifstream	is(filename.c_str());

			if (!is)
			{
				std::cout << "Error: could not open file." << std::endl;
				return (1);
			}

			std::string	input;
			bool		i = false;

			while (getline(is, input))
			{
				if (input == "date | value" && i == false)
					getline(is, input);
				i = true;

				if (!input.empty())
					btc.checkAnd_display(input);
				else
					std::cout << "Error : bad input => empty line" << std::endl;
			}
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	else
	{
		std::cout << "Error : invalid number of arguments." << std::endl;
		return (1);
	}

	return (0);
}

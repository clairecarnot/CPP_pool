# include <string>
# include <iostream>
# include "../includes/Contact.hpp"
# include "../includes/PhoneBook.hpp"

int	main()
{
	PhoneBook	phoneBook;
	std::string		input;

	std::cout << "╔═════════════════════════════════════════════════════════╗" << std::endl;
	std::cout << "║";
	std::cout << std::setw(58) << "    WELCOME TO YOUR \e[9mCRAPPY\e[0m AWESOME PHONEBOOK FRIEND !    ";
	std::cout << "║" << std::endl;
	std::cout << "╚═════════════════════════════════════════════════════════╝" << std::endl;
	while (1)
	{
		std::cout << "Enter 'ADD', 'SEARCH' or 'EXIT'" << std::endl;
		if (!std::getline(std::cin, input) || std::cin.eof())
			break ;
		if (input == "ADD")
		{
			if (!phoneBook.addContact())
				break ;
		}
		else if (input == "SEARCH")
		{
			if (!phoneBook.searchContact())
				break ;
		}
		else if (input == "EXIT")
		{
			std::cout << "╔═════════════════════════════════════════════════════════╗" << std::endl;
			std::cout << "║";
			std::cout << std::setw(57) << "        EXITING... DON'T FORGET ME ! =')          ";
			std::cout << "║" << std::endl;
			std::cout << "╚═════════════════════════════════════════════════════════╝" << std::endl;
			break ;
		}
		else
			std::cout << "Invalid command." << std::endl;
	}
	return 0;
}

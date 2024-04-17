#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _noContacts(0), _quit(false)
{
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

bool	PhoneBook::addContact(void)
{
	std::string	input;
	while (!_quit)
	{
		input = _getInput("first name : ");
		if (_quit || this->_contactList[_index].setFirstName(input))
			break ;
	}
	while (!_quit)
	{
		input = _getInput("last name : ");
		if (_quit || this->_contactList[_index].setLastName(input))
			break ;
	}
	while (!_quit)
	{
		input = _getInput("nickname : ");
		if (_quit || this->_contactList[_index].setNickname(input))
			break ;
	}
	while (!_quit)
	{
		input = _getInput("phone number : ");
		if (_quit || this->_contactList[_index].setPhoneNumber(input))
			break ;
	}
	while (!_quit)
	{
		input = _getInput("darkest secret : ");
		if (_quit || this->_contactList[_index].setDarkSecret(input))
			break ;
	}
	if (_quit)
	{
		_quit = false;
		return (false);
	}
	this->_index++;
	this->_noContacts = 1;
	std::cout << "Contact no " << this->_index << " added !" << std::endl;
	if (this->_index > 7)
		this->_index = 0;
	return (true) ;
}

bool	PhoneBook::searchContact(void)
{
	std::string	input;

	if (_noContacts == 0)
	{
		std::cout << "ADD at least one contact to activate SEARCH" << std::endl;
		return (true) ;
	}
	_displayAllContacts();
	while (!_quit)
	{
		input = _getInput("number of contact to display : ");
		if (_quit)
			break ;
		if (_searchContactIndex((std::string const) input))
			break ;
	}
	if (_quit)
	{
		_quit = false;
		return (false);
	}
	return (true);
}

bool	PhoneBook::_searchContactIndex(std::string const str) const
{
	int	index;

	if (!str.empty() && str.length() == 1 && std::isdigit(str[0]))
	{
		index = str[0] - '0';
		if (index >= 0 && index <= 7)
		{
			if (this->_contactList[index].isEmpty())
				std::cout << "Contact no " << index << " not created yet." << std::endl;
			else
			{
				this->_contactList[index].displayContactInfo();
				return (true);
			}
		}
		else
			std::cout << "Invalid index number." << std::endl;
	}
	else
		std::cout << "Invalid index number." << std::endl;
	return (false);
}

std::string	PhoneBook::_getInput(std::string const str)
{
	std::string	input;

	std::cout << "Enter " << str;
	if (!std::getline(std::cin, input) || std::cin.eof())
	{
		this->_quit = true;
		return (std::string());
	}
	if (input.empty())
		return (input);
	input = _trimWspc(input);
	return (input);
}

std::string	PhoneBook::_trimWspc(std::string str)
{
	std::string	set("\t\n\r\v\f ");
	size_t	start;
	size_t	end;

	start = str.find_first_not_of(set);
	end = str.find_last_not_of(set);
	if (start == end)
		return (str);
	else
		return (str.substr(start, end - start + 1));
}

void	PhoneBook::_displayAllContacts(void) const
{
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	std::cout << "|   INDEX  |FIRST NAME| LAST NAME| NICKNAME |" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	for (int i = 0; i < 8; i++)
		_displayEachContact(i);
	std::cout << std::endl;
	return ;
}

void	PhoneBook::_displayEachContact(int const i) const
{
	if (this->_contactList[i].isEmpty())
		return ;
	std::cout << "|" << std::setw(10) << i << "|";
	_printInfo(this->_contactList[i].getFirstName());
	_printInfo(this->_contactList[i].getLastName());
	_printInfo(this->_contactList[i].getNickname());
	std::cout << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	return ;
}

void	PhoneBook::_printInfo(std::string str) const
{
	if (str.length() > 10)
	{
		str.resize(9);
		str += ".";
	}
	std::cout << std::setw(10) << str << "|";
	return ;
}

int	PhoneBook::_index = 0;

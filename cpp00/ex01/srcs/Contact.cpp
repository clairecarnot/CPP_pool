#include "../includes/Contact.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

bool	Contact::setFirstName(std::string const str)
{
	if (str.empty())
		return (false);
	else if (!_containsAlphaOnly(str))
	{
		std::cout << "Names should contain alpha characters only !" << std::endl;
		return (false);
	}
	this->_firstName = str;
	return true;
}

bool	Contact::setLastName(std::string const str)
{
	if (str.empty())
		return (false);
	else if (!_containsAlphaOnly(str))
	{
		std::cout << "Names should contain alpha characters only !" << std::endl;
		return (false);
	}
	this->_lastName = str;
	return true;
}

bool	Contact::setNickname(std::string const str)
{
	if (str.empty())
		return (false);
	else if (!_containsAlphaOnly(str))
	{
		std::cout << "Names should contain alpha characters only !" << std::endl;
		return (false);
	}
	this->_nickName = str;
	return true;
}

bool	Contact::setPhoneNumber(std::string const str)
{
	if (str.empty())
		return (false);
	else if (!_containsDigitsOnly(str))
	{
		std::cout << "Phone numbers should contain digits only !" << std::endl;
		return (false);
	}
	this->_phoneNumber = str;
	return true;
}

bool	Contact::setDarkSecret(std::string const str)
{
	if (str.empty())
		return (false);
	this->_darkestSecret = str;
	return true;
}

bool	Contact::_containsDigitsOnly(std::string const str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

bool	Contact::_containsAlphaOnly(std::string const str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isalpha(str[i]) && str[i] != ' ' && str[i] != '-')
			return false;
	}
	return true;
}

bool	Contact::isEmpty(void) const
{
	if (this->_firstName.empty()
		|| this->_lastName.empty()
		|| this->_nickName.empty()
		|| this->_phoneNumber.empty()
		|| this->_darkestSecret.empty())
			return (true);
	return (false);
}

std::string const	Contact::getFirstName(void) const
{
	return (this->_firstName);
}

std::string const	Contact::getLastName(void) const
{
	return (this->_lastName);
}

std::string const	Contact::getNickname(void) const
{
	return (this->_nickName);
}

std::string const	Contact::getPhoneNumber(void) const
{
	return (this->_phoneNumber);
}

std::string const	Contact::getDarkSecret(void) const
{
	return (this->_darkestSecret);
}

void	Contact::displayContactInfo(void) const
{
	std::cout << "First name : " << this->_firstName << std::endl;
	std::cout << "Last name : " << this->_lastName << std::endl;
	std::cout << "Nickname : " << this->_nickName << std::endl;
	std::cout << "Phone number : " << this->_phoneNumber << std::endl;
	std::cout << "Darkest Secret : " << this->_darkestSecret << std::endl;
	return ;
}

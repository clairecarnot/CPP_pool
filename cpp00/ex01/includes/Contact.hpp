#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <cctype>
# include <iomanip>

class	Contact
{
	public:
		Contact();
		~Contact();

		bool	setFirstName(std::string const str);
		bool	setLastName(std::string const str);
		bool	setNickname(std::string const str);
		bool	setPhoneNumber(std::string const str);
		bool	setDarkSecret(std::string const str);
		bool	isEmpty(void) const;
		void	displayContactInfo(void) const;
		std::string const	getFirstName(void) const;
		std::string const	getLastName(void) const;
		std::string const	getNickname(void) const;
		std::string const	getPhoneNumber(void) const;
		std::string const	getDarkSecret(void) const;

	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_darkestSecret;

		bool	_containsDigitsOnly(std::string const str);
		bool	_containsAlphaOnly(std::string const str);
};

#endif

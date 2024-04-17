#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class	PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();

		bool		addContact(void);
		bool		searchContact(void);

	private:
		Contact		_contactList[8];
		static int	_index;
		int		_noContacts;
		bool		_quit;

		std::string	_getInput(std::string const str);
		std::string	_trimWspc(std::string str);
		void		_displayAllContacts(void) const;
		void		_displayEachContact(int const i) const;
		void		_printInfo(std::string str) const;
		bool		_searchContactIndex(std::string const str) const;
};

#endif

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class	Weapon
{
	public:
		Weapon(void);
		Weapon(std::string type);
		~Weapon(void);

		std::string const	&getType(void) const;
		void			setType(std::string const type);

	private:
		std::string	_type;
};

#endif

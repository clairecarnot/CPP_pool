#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class	HumanA
{
	public:
		HumanA(std::string const name, Weapon &weapon);
		~HumanA(void);

		void	attack(void) const;

	private:
		Weapon			&_weapon;
		std::string const	_name;
};

#endif

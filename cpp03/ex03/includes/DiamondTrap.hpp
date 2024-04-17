#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <string>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap(void);
		DiamondTrap(std::string const &name);
		DiamondTrap(DiamondTrap const &dt);
		~DiamondTrap(void);

		DiamondTrap	&operator=(DiamondTrap const &dt);

		void	attack(const std::string &target);
		void	whoAmI(void);

	private:
		std::string	_name;
};

#endif

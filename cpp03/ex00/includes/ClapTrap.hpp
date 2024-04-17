#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class	ClapTrap
{
	public:
		ClapTrap(void);
		ClapTrap(std::string const &name);
		ClapTrap(ClapTrap const &ct);
		~ClapTrap(void);

		ClapTrap	&operator=(ClapTrap const &ct);

		std::string	getName(void) const;
		int		getHealth(void) const;
		int		getEnergy(void) const;
		int		getAttackDamages(void) const;
		void		setAttackDamages(unsigned int const &amount);

		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	private:
		std::string	_name;
		int		_hitPoints;
		int		_energyPoints;
		int		_attackDamage;

};

#endif

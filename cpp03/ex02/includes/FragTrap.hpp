#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string const &name);
		FragTrap(FragTrap const &ft);
		~FragTrap(void);

		FragTrap	&operator=(FragTrap const &ft);

		void	highFivesGuys(void);

	private:

};

#endif

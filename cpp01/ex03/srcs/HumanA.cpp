#include "../includes/HumanA.hpp"

HumanA::HumanA(std::string const name, Weapon &weapon) : _weapon(weapon), _name(name)
{
	return ;
}

HumanA::~HumanA(void)
{
	return ;
}

void	HumanA::attack(void) const
{
	std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
	return ;
}

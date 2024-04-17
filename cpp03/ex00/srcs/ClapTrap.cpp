#include "ClapTrap.hpp"

// CONSTRUCTORS ------------------------------------------------------------- //

ClapTrap::ClapTrap(void) : _name("Unnamed"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string const &name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Overloaded constructor called." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &ct) : _name(ct._name), _hitPoints(ct._hitPoints), _energyPoints(ct._energyPoints), _attackDamage(ct._attackDamage)
{
	std::cout << "Copy constructor called." << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Default destructor called." << std::endl;
}

// OPERATORS ---------------------------------------------------------------- //

ClapTrap	&ClapTrap::operator=(ClapTrap const &ct)
{
	if (this != &ct)
	{
		this->_name = ct._name;
		this->_hitPoints = ct._hitPoints;
		this->_energyPoints = ct._energyPoints;
		this->_attackDamage = ct._attackDamage;
	}
	return (*this);
}

// GET / SET ---------------------------------------------------------------- //
 
std::string	ClapTrap::getName(void) const
{
	return (this->_name);
}

int		ClapTrap::getHealth(void) const
{
	return (this->_hitPoints);
}

int		ClapTrap::getEnergy(void) const
{
	return (this->_energyPoints);
}

int		ClapTrap::getAttackDamages(void) const
{
	return (this->_attackDamage);
}

void	ClapTrap::setAttackDamages(unsigned int const &amount)
{
	this->_attackDamage = amount;
}

// FUNCTIONS ---------------------------------------------------------------- //

void	ClapTrap::attack(const std::string &target)
{
	if (this->_hitPoints == 0)
		std::cout << "Oooops can't attack ! ClapTrap " << this->_name << " is already dead !" << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << "ClapTrap " << this->_name << " does not have enough energy to attack !" << std::endl;
	else
	{
		this->_energyPoints--;
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage !" << std::endl << "ClapTrap " << this->_name << " has " << this->_energyPoints << " energy points left." << std::endl;
	}
	std::cout << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
		std::cout << "ClapTrap " << this->_name << " is already dead, it cannot lose any more points !" << std::endl;
	else
	{
		this->_hitPoints -= amount;
		if (this->_hitPoints < 0)
			this->_hitPoints = 0;
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage, its health points falls to : " << this->_hitPoints << std::endl;
	}
	std::cout << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0)
		std::cout << "Oooops can't heal ! " << "ClapTrap " << this->_name << " is already dead !" << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << "ClapTrap " << this->_name << " does not have enough energy points to repair itself !" << std::endl;
	else 
	{
		this->_energyPoints--;
		this->_hitPoints += amount;
		std::cout << "ClapTrap " << this->_name << " repairs itself and gains " << amount << " hit points, its health points are now at : " << this->_hitPoints << std::endl << "ClapTrap " << this->_name << " has " << this->_energyPoints << " energy points left." << std::endl;
	}
	std::cout << std::endl;
}

// STATIC ELEMENTS ---------------------------------------------------------- //

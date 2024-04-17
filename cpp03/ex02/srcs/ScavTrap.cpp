#include "ScavTrap.hpp"

// CONSTRUCTORS ------------------------------------------------------------- //

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "Default constructor for ScavTrap called." << std::endl;
}

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "Overloaded constructor for ScavTrap called." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &st) : ClapTrap(st._name)
{
	this->_hitPoints = st._hitPoints;
	this->_energyPoints = st._energyPoints;
	this->_attackDamage = st._attackDamage;
	std::cout << "Copy constructor for ScavTrap called." << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Default destructor for ScavTrap called." << std::endl;
}

// OPERATORS ---------------------------------------------------------------- //

ScavTrap	&ScavTrap::operator=(ScavTrap const &st)
{
	if (this != &st)
	{
		this->_name = st._name;
		this->_hitPoints = st._hitPoints;
		this->_energyPoints = st._energyPoints;
		this->_attackDamage = st._attackDamage;
	}
	return (*this);
}

// GET / SET ---------------------------------------------------------------- //
 
// FUNCTIONS ---------------------------------------------------------------- //

void	ScavTrap::attack(const std::string &target)
{
	if (this->_hitPoints == 0)
		std::cout << "Oooops can't attack ! ScavTrap " << this->_name << " is already dead !" << std::endl;
	else if (this->_energyPoints == 0)
		std::cout << "ScavTrap " << this->_name << " does not have enough energy to attack !" << std::endl;
	else
	{
		this->_energyPoints--;
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage !" << std::endl << "ScavTrap " << this->_name << " has " << this->_energyPoints << " energy points left." << std::endl;
	}
	std::cout << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
	std::cout << std::endl;
}

// STATIC ELEMENTS ---------------------------------------------------------- //

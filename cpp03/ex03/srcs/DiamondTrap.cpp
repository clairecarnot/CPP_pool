#include "DiamondTrap.hpp"

// CONSTRUCTORS ------------------------------------------------------------- //

DiamondTrap::DiamondTrap(void) : ScavTrap(), FragTrap()
{
	std::cout << "Default constructor for DiamondTrap called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string const &name) : ClapTrap(name + "_clap_name"), ScavTrap(name + "_scav_name"), FragTrap(name + "_frag_name"), _name(name)
{
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "Overloaded constructor for DiamondTrap called." << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &dt) : ClapTrap(dt._name + "_clap_name"), ScavTrap(dt._name + "_scav_name"), FragTrap(dt._name + "_frag_name"), _name(dt._name)
{
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "Copy constructor for DiamondTrap called." << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "Default destructor for DiamondTrap called." << std::endl;
}

// OPERATORS ---------------------------------------------------------------- //

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &dt)
{
	if (this != &dt)
	{
		this->_name = dt._name;
		this->ClapTrap::_name = dt.ClapTrap::_name;
		this->_hitPoints = dt._hitPoints;
		this->_energyPoints = dt._energyPoints;
		this->_attackDamage = dt._attackDamage;
	}
	return (*this);
}

// GET / SET ---------------------------------------------------------------- //

// FUNCTIONS ---------------------------------------------------------------- //

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "Who I am ? My name is " << this->_name << " but you can also call my ClapTrap name : " << this->ClapTrap::_name << std::endl;
	std::cout << std::endl;
}

// STATIC ELEMENTS ---------------------------------------------------------- //

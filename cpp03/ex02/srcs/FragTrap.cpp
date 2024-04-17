#include "FragTrap.hpp"

// CONSTRUCTORS ------------------------------------------------------------- //

FragTrap::FragTrap(void) : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "Default constructor for FragTrap called." << std::endl;
}

FragTrap::FragTrap(std::string const &name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "Overloaded constructor for FragTrap called." << std::endl;
}

FragTrap::FragTrap(FragTrap const &ft) : ClapTrap(ft._name)
{
	this->_hitPoints = ft._hitPoints;
	this->_energyPoints = ft._energyPoints;
	this->_attackDamage = ft._attackDamage;
	std::cout << "Copy constructor for FragTrap called." << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "Default destructor for FragTrap called." << std::endl;
}

// OPERATORS ---------------------------------------------------------------- //

FragTrap	&FragTrap::operator=(FragTrap const &ft)
{
	if (this != &ft)
	{
		this->_name = ft._name;
		this->_hitPoints = ft._hitPoints;
		this->_energyPoints = ft._energyPoints;
		this->_attackDamage = ft._attackDamage;
	}
	return (*this);
}

// GET / SET ---------------------------------------------------------------- //
 
// FUNCTIONS ---------------------------------------------------------------- //

void	FragTrap::highFivesGuys(void)
{
	std::cout << this->_name << " requests a positive HIGH FIVES NOW !!!" << std::endl;
	std::cout << std::endl;
}

// STATIC ELEMENTS ---------------------------------------------------------- //

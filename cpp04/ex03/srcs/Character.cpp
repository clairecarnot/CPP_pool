#include "Character.hpp"

// CONSTRUCTORS / DESTRUCTORS -------------------------------------------------//

Character::Character(void) : _name("noName")
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(std::string const &name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(Character const &src) : _name(src._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (src._inventory[i] != NULL)
			this->_inventory[i] = src._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
		{
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}
}

// OPERATORS ------------------------------------------------------------------//

Character	&Character::operator=(Character const &src)
{
	if (this != &src)
	{
		this->_name = src._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i] != NULL)
				delete (this->_inventory[i]);
			if (src._inventory[i] != NULL)
				this->_inventory[i] = src._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
	return (*this);
}

// GETTERS / SETTERS ----------------------------------------------------------// 

std::string const	&Character::getName(void) const
{
	return (this->_name);
}

// FUNCTIONS ------------------------------------------------------------------// 

void	Character::equip(AMateria* m)
{
	if (m == NULL)
	{
		std::cout << this->_name << RED " cannot equip: unexisting materia" RESET << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			return ;
		}
	}
	std::cout << this->_name << RED " cannot equip: inventory is full !" RESET << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		std::cout << this->_name << RED " cannot unequip: unexisting equipment slot" RESET << std::endl;
	else if (this->_inventory[idx] == NULL)
		std::cout << this->_name << RED " cannot unequip: slot already unequipped" RESET << std::endl;
	else
	{
		std::cout << this->_name << " drops materia : " << this->_inventory[idx]->getType() << " on the floor" << std::endl;
		this->_inventory[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		std::cout << this->_name << RED " cannot use unexisting equipment slot" RESET << std::endl;
	else if (this->_inventory[idx] == NULL)
		std::cout << this->_name << RED " cannot use unexisting equipment" RESET << std::endl;
	else if ((this->_inventory[idx]->getType() != "ice") && (this->_inventory[idx]->getType() != "cure"))
		std::cout << this->_name << RED " cannot equip: invalid materia" RESET << std::endl;
	else
		this->_inventory[idx]->use(target);
}

AMateria const	*Character::droppedMateria(int idx) const
{
	if ((idx > 0 && idx < 4) && this->_inventory[idx])
		return (this->_inventory[idx]);
	else
		return (NULL);
}

void	Character::printInventory(void) const
{
	std::cout << ITAL "CHARACTER INVENTORY:" RESET << std::endl;
	std::cout << "+----------+----------+" << std::endl;
	std::cout << "|   slot   | materia  |" << std::endl;
	std::cout << "+----------+----------+" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
		{
			std::cout << "|" << std::setw(10) << i << "|" << std::setw(10) << this->_inventory[i]->getType() << "|" << std::endl;
			std::cout << "+----------+----------+" << std::endl;
		}
		else
		{
			std::cout << "|" << std::setw(10) << i << "|" << std::setw(10) << " " << "|" << std::endl;
			std::cout << "+----------+----------+" << std::endl;
		}
	}
}

// STATIC ELEMENTS ------------------------------------------------------------//

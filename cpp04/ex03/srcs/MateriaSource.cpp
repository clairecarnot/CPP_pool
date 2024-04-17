#include "MateriaSource.hpp"

// CONSTRUCTORS / DESTRUCTORS -------------------------------------------------//

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &src)
{
	for (int i = 0; i < 4; i++)
	{
		if (!src._inventory[i])
			this->_inventory[i] = NULL;
		else
			this->_inventory[i] = src._inventory[i]->clone();
	}
}

MateriaSource::~MateriaSource(void)
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

MateriaSource	&MateriaSource::operator=(MateriaSource const &src)
{
	if (this != &src)
	{
		for (int i = 0; i < 4; i++)
		{
			if (!src._inventory[i])
				this->_inventory[i] = NULL;
			else
				this->_inventory[i] = src._inventory[i]->clone();
		}
	}
	return (*this);
}

// GETTERS / SETTERS ----------------------------------------------------------// 


// FUNCTIONS ------------------------------------------------------------------// 

void	MateriaSource::learnMateria(AMateria *src)
{
	if (src)
	{
		for (int i = 0; i < 4; i++)
		{
			if (!this->_inventory[i])
			{
				this->_inventory[i] = src;
				return ;
			}
		}
		std::cout << RED "Can't stock materia " << src->getType() << " : no more slots available in this inventory" RESET << std::endl;
	}
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] && this->_inventory[i]->getType() == type)
			return (this->_inventory[i]->clone());
	}
	std::cout << RED "Cannot create Materia - unknown type" RESET << std::endl;
	return (NULL);
}

void	MateriaSource::printTemplates(void) const
{
	std::cout << ITAL "MATERIA INVENTORY:" RESET << std::endl;
	std::cout << "+----------+----------+" << std::endl;
	std::cout << "|   slot   | template |" << std::endl;
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

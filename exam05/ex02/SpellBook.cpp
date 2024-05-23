#include "SpellBook.hpp"

// Constructors / Destructor ------------------------------------------------------ //

SpellBook::SpellBook(void)
{
}

SpellBook::~SpellBook(void)
{
	for (std::vector<ASpell*>::iterator it = this->_sp.begin(); it != this->_sp.end();)
	{
		delete (*it);
		it = this->_sp.erase(it);
	}
}

// Operators ---------------------------------------------------------------------- //


// Getters / setters -------------------------------------------------------------- //


// Fonctions ---------------------------------------------------------------------- //

void	SpellBook::learnSpell(ASpell* spell)
{
	for (std::vector<ASpell*>::iterator it = this->_sp.begin(); it != this->_sp.end(); ++it)
	{
		if ((*it)->getName() == spell->getName())
			return ;
	}
	this->_sp.push_back(spell->clone());
}

void	SpellBook::forgetSpell(std::string const &spell)
{
	for (std::vector<ASpell*>::const_iterator it = this->_sp.begin(); it != this->_sp.end();)
	{
		if ((*it)->getName() == spell)
		{
			delete (*it);
			it = this->_sp.erase(it);
			return ;
		}
		else
			it++;
	}
}

ASpell*	SpellBook::createSpell(std::string const &spell)
{
	for (std::vector<ASpell*>::iterator it = this->_sp.begin(); it != this->_sp.end(); ++it)
	{
		if ((*it)->getName() == spell)
			return ((*it)->clone());
	}
	return (NULL);
}

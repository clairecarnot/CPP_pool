#include "SpellBook.hpp"

// ------------------------------------------------------- //

SpellBook::SpellBook()
{
}

SpellBook::SpellBook(SpellBook const &src)
{
	*this = src;
}

SpellBook::~SpellBook()
{
	for (std::map<std::string, ASpell *>::iterator it = _arr.begin(); it != _arr.end(); ++it)
	{
		delete it->second;
	}
	_arr.clear();
}

// ------------------------------------------------------- //

SpellBook	&SpellBook::operator=(SpellBook const &src)
{
	if (this != &src)
	{
		this->_arr = src._arr;
	}
	return (*this);
}

// ------------------------------------------------------- //

void	SpellBook::learnSpell(ASpell *spell)
{
	if (spell)
	{
		if (_arr.find(spell->getName()) == _arr.end())
			_arr[spell->getName()] = spell->clone();
	}
}

void	SpellBook::forgetSpell(std::string const &spellName)
{
	std::map<std::string, ASpell *>::iterator it = _arr.find(spellName);
	if (it != _arr.end())
	{
		_arr.erase(it);
	}
}

ASpell*	SpellBook::createSpell(std::string const &spellName)
{
	if (_arr.find(spellName) != _arr.end())
		return (_arr[spellName]);
	else
		return (NULL);
}


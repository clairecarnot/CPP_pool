#include "Warlock.hpp"

// Constructors / Destructor ------------------------------------------------------ //

Warlock::Warlock(std::string const &name, std::string const &title) : _name(name), _title(title)
{
	std::cout << this->_name << ": This looks like another boring day." << std::endl;
	this->_book = new SpellBook();
}

Warlock::Warlock(Warlock const &src) : _name(src._name), _title(src._title)
{
}

Warlock::~Warlock(void)
{
	std::cout << this->_name << ": My job here is done!" << std::endl;
	delete (this->_book);
}

// Operators ---------------------------------------------------------------------- //

Warlock	&Warlock::operator=(Warlock const &src)
{
	if (this != &src)
	{
		this->_name = src._name;
		this->_title = src._title;
	}
	return (*this);
}

// Getters / setters -------------------------------------------------------------- //

std::string const	&Warlock::getName(void) const
{
	return (this->_name);
}

std::string const	&Warlock::getTitle(void) const
{
	return (this->_title);
}

void	Warlock::setTitle(std::string const &title)
{
	this->_title = title;
}

// Fonctions ---------------------------------------------------------------------- //

void	Warlock::introduce() const
{
	std::cout << this->getName() << ": I am " << this->getName() << ", " << this->getTitle() << "!" << std::endl;
}

void	Warlock::learnSpell(ASpell *spell)
{
	this->_book->learnSpell(spell);
}

void	Warlock::forgetSpell(std::string const &spell)
{
	this->_book->forgetSpell(spell);
}

void	Warlock::launchSpell(std::string const &spell, ATarget const &target)
{
	ASpell	*created = this->_book->createSpell(spell);
	if (created)
		created->launch(target);
}

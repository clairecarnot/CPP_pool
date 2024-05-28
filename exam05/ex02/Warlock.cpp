#include "Warlock.hpp"

// ------------------------------------------------------------------ //

Warlock::Warlock()
{
}

Warlock::Warlock(std::string const &name, std::string const &title) : _name(name), _title(title)
{
	std::cout << this->_name << ": This looks like another boring day." << std::endl;
}

Warlock::Warlock(Warlock const &src)
{
	*this = src;
}

Warlock::~Warlock()
{
	std::cout << this->_name << ": My job here is done!" << std::endl;
}

// ------------------------------------------------------------------ //

Warlock	&Warlock::operator=(Warlock const &src)
{
	if (this != &src)
	{
		this->_name = src.getName();
		this->_title = src.getTitle();
	}
	return (*this);
}

// ------------------------------------------------------------------ //


std::string const	&Warlock::getName() const
{
	return (this->_name);
}

std::string const	&Warlock::getTitle() const
{
	return (this->_title);
}

void	Warlock::setTitle(std::string const &title)
{
	this->_title = title;
}

// ------------------------------------------------------------------ //

void	Warlock::introduce() const
{
	std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!" << std::endl;
}

void	Warlock::learnSpell(ASpell *spell)
{
	_sB.learnSpell(spell);
}

void	Warlock::forgetSpell(std::string spell)
{
	_sB.forgetSpell(spell);
}

void	Warlock::launchSpell(std::string spell, ATarget const &target)
{
	ASpell	*s = _sB.createSpell(spell);
	if (s)
		s->launch(target);
}

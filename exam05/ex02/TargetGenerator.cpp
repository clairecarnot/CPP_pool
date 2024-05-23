#include "TargetGenerator.hpp"

// Constructors / Destructor ------------------------------------------------------ //

TargetGenerator::TargetGenerator(void)
{
}

TargetGenerator::~TargetGenerator(void)
{
	for (std::vector<ATarget*>::iterator it = this->_tg.begin(); it != this->_tg.end();)
	{
		delete (*it);
		it = this->_tg.erase(it);
	}
}

// Operators ---------------------------------------------------------------------- //


// Getters / setters -------------------------------------------------------------- //


// Fonctions ---------------------------------------------------------------------- //

void	TargetGenerator::learnTargetType(ATarget* target)
{
	for (std::vector<ATarget*>::iterator it = this->_tg.begin(); it != this->_tg.end(); ++it)
	{
		if ((*it)->getType() == target->getType())
			return ;
	}
	this->_tg.push_back(target->clone());
}

void	TargetGenerator::forgetTargetType(std::string const &type)
{
	for (std::vector<ATarget*>::const_iterator it = this->_tg.begin(); it != this->_tg.end();)
	{
		if ((*it)->getType() == type)
		{
			delete (*it);
			it = this->_tg.erase(it);
			return ;
		}
		else
			it++;
	}
}

ATarget*	TargetGenerator::createTarget(std::string const &type)
{
	for (std::vector<ATarget *>::iterator it = this->_tg.begin(); it != this->_tg.end(); ++it)
	{
		if ((*it)->getType() == type)
			return ((*it)->clone());
	}
	return (NULL);
}

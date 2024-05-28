#include "TargetGenerator.hpp"

// ---------------------------------------------------//

TargetGenerator::TargetGenerator()
{
}

TargetGenerator::TargetGenerator(TargetGenerator const &src)
{
	*this = src;
}

TargetGenerator::~TargetGenerator()
{
	for (std::map<std::string, ATarget *>::iterator it = _gen.begin(); it != _gen.end(); ++it)
		delete it->second;
	_gen.clear();
}

// ---------------------------------------------------//

TargetGenerator	&TargetGenerator::operator=(TargetGenerator const &src)
{
	if (this != &src)
		return (*this);
	return (*this);
}

// ---------------------------------------------------//

void		TargetGenerator::learnTargetType(ATarget* target)
{
	if (target)
	{
		if (_gen.find(target->getType()) == _gen.end())
			_gen[target->getType()] = target->clone();
	}
}

void		TargetGenerator::forgetTargetType(std::string const &type)
{
	std::map<std::string, ATarget *>::iterator it = _gen.find(type);
	if (it != _gen.end())
	{
		_gen.erase(type);
	}
}

ATarget*	TargetGenerator::createTarget(std::string const &type)
{
	if (_gen.find(type) != _gen.end())
		return (_gen[type]);
	return (NULL);
}

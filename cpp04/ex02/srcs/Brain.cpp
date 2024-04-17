#include "Brain.hpp"

// CONSTRUCTORS / DESTRUCTORS -------------------------------------------------//

Brain::Brain(void)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "";
	std::cout << "Default constructor for \e[1;37mBrain\e[0m" << std::endl;
}

Brain::Brain(Brain const &src)
{
	for (int i = 0 ; i < 100; i++)
		this->_ideas[i] = src._ideas[i];
	std::cout << "Copy constructor for \e[1;37mBrain\e[0m" << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "Default destructor for \e[1;37mBrain\e[0m" << std::endl;
}

// OPERATORS ------------------------------------------------------------------//

Brain	&Brain::operator=(Brain const &src)
{
	if (this != &src)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = src._ideas[i];
	}
	return (*this);
}

// GETTERS / SETTERS ----------------------------------------------------------// 

std::string const	Brain::getIdeas(int const i) const
{
	if (i < 0 || i > 99)
		return ("*Nothing happens at this depth of the Brain...*");
	else
		return (this->_ideas[i]);
}

void		Brain::setIdeas(int const i, std::string const &idea)
{
	if (i < 0 || i > 99)
		return ;
	else
		this->_ideas[i] = idea;
}

// FUNCTIONS ------------------------------------------------------------------// 

// STATIC ELEMENTS ------------------------------------------------------------//

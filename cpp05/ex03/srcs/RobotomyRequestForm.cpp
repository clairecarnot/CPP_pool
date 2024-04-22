#include "RobotomyRequestForm.hpp"

// CONSTRUCTORS / DESTRUCTORS -------------------------------------------------------------- //

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("Robotomy Request", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm("Robotomy Request", 72, 45), _target(src._target)
{
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

// OPERATORS ------------------------------------------------------------------------------- //

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &src)
{
	if (this != &src)
		this->_target = src._target;
	return (*this);
}

// GETTERS / SETTERS ----------------------------------------------------------------------- //

std::string	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

// FUNCTIONS ------------------------------------------------------------------------------- //

void	RobotomyRequestForm::doExecute(void) const
{
	srand(time(0));
	std::cout << GREY << this->getName() << ": trrrrrtrrrrrtrrrrr.....bip...trrbipbip....trrtrrr" RESET << std::endl;
	if (std::rand() % 2)
		std::cout << GREY << this->getName() << ": SUCCESS ! " << this->_target << " has been robotomized." RESET << std::endl;
	else
		std::cout << GREY << this->getName() << ": FAILURE ! " << this->_target << " could not be robotomized." RESET << std::endl;
}

// STATIC ELEMENTS ------------------------------------------------------------------------- //


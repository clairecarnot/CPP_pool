#include "PresidentialPardonForm.hpp"

// CONSTRUCTORS / DESTRUCTORS -------------------------------------------------------------- //

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("Presidential Pardon", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm("Presidential Pardon", 25, 5), _target(src._target)
{
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

// OPERATORS ------------------------------------------------------------------------------- //

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &src)
{
	if (this != &src)
		this->_target = src._target;
	return (*this);
}

// GETTERS / SETTERS ----------------------------------------------------------------------- //

std::string	PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

// FUNCTIONS ------------------------------------------------------------------------------- //

void	PresidentialPardonForm::doExecute(void) const
{
	std::cout << GREY << this->_target << " has been pardonned by Zaphod Beeblebrox." RESET << std::endl;
}

// STATIC ELEMENTS ------------------------------------------------------------------------- //


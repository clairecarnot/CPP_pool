#include "Intern.hpp"

// CONSTRUCTORS / DESTRUCTORS -------------------------------------------------------------- //

Intern::Intern(void)
{
}

Intern::Intern(Intern const &src)
{
	(void)src;
}

Intern::~Intern(void)
{
}

// OPERATORS ------------------------------------------------------------------------------- //

Intern	&Intern::operator=(Intern const &src)
{
	(void)src;
	return (*this);
}

// GETTERS / SETTERS ----------------------------------------------------------------------- //


// FUNCTIONS ------------------------------------------------------------------------------- //

AForm	*Intern::createSCF(std::string const &target)
{
	return (new ShrubberyCreationForm(target));
};

AForm	*Intern::createRRF(std::string const &target)
{
	return (new RobotomyRequestForm(target));
};

AForm	*Intern::createPPF(std::string const &target)
{
	return (new PresidentialPardonForm(target));
};

AForm	*Intern::makeForm(std::string const &name, std::string const &target)
{
	typedef	AForm	*(Intern::*fptr)(std::string const &target);
	std::string	forms[3] = {"Shrubbery Creation", "Robotomy Request", "Presidential Pardon"};
	fptr		formsCreate[3] = {&Intern::createSCF, &Intern::createRRF, &Intern::createPPF};

	for (int i = 0; i < 3; i++)
	{
		if (name == forms[i])
		{
			std::cout << "Intern creates " << LGREEN << name << RESET << " Form." << std::endl;
			return ((this->*formsCreate[i])(target));
		}
	}
	throw Intern::UnexistingFormException();
	return (NULL);
}

// STATIC ELEMENTS ------------------------------------------------------------------------- //


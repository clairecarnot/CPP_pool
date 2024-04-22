#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

void	testFormCreation(std::string const &name, std::string const &target)
{
	Intern		intern;
	Bureaucrat	bureaucrat("Julie", 6);

	try
	{
		AForm *newForm = intern.makeForm(name, target);
		bureaucrat.signForm(*newForm);
		bureaucrat.executeForm(*newForm);
		delete newForm;
	}
	catch (Intern::UnexistingFormException &e)
	{
		std::cout << name << " : " << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
}

int	main(void)
{
	testFormCreation("Shrubbery Creation", "garden");
	testFormCreation("Robotomy Request", "Bob");
	testFormCreation("Presidential Pardon", "Jessie James");
	testFormCreation("Blablabli blublublu", "Something");

	return (0);
}

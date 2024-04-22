#include "Bureaucrat.hpp"

void	createForm(std::string const name, int const sG, int const eG)
{
	try
	{
		Form form(name, sG, eG);
		std::cout << form << LGREEN " created" RESET << std::endl;
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

int	main(void)
{
	Bureaucrat ceo("CEO", 1);
	Bureaucrat admin("Admin", 50);
	Bureaucrat intern("Intern", 135);
	
	std::cout << WBLUE << "Test form limits ------------------------------------------- #" RESET << std::endl;

	// OK:
	createForm("A1", 80, 20);
	createForm("B2", 5, 106);

	// Too high:
	createForm("C3", 0, 14);
	createForm("C3", 76, -17);

	// Too low:
	createForm("D4", 93, 173);
	createForm("D4", 800, 45);

	std::cout << WBLUE << "Test copy & assign. ---------------------------------------- #" RESET << std::endl;
	
	// Copy and assignment:
	Form e5("E5", 7, 31);
	std::cout << e5 << LGREEN " created" RESET << std::endl;
	Form f6("F6", 130, 12);
	std::cout << f6 << LGREEN " created" RESET << std::endl;
	ceo.signForm(e5);
	Form g7(e5);
	std::cout << g7 << LGREEN " created" RESET << std::endl;
	f6 = g7;
	std::cout << f6 << LGREEN " after assignment" RESET << std::endl;

	std::cout << WBLUE << "Test signature grades -------------------------------------- #" RESET << std::endl;

	Form h8("H8", 8, 90);
	intern.signForm(h8);	
	admin.signForm(h8);	
	ceo.signForm(h8);	

	std::cout << WBLUE << "Test signature standalone ---------------------------------- #" RESET << std::endl;
	Form i9("I9", 58, 13);
	try
	{
		i9.beSigned(intern);
		std::cout << admin.getName() << LBLUE << " signed " << RESET << i9.getName() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << intern.getName() << ORANGE " couldn't sign " RESET << i9.getName() << " because " << e.what() << std::endl;
	}
	try
	{
		i9.beSigned(admin);
		std::cout << admin.getName() << LBLUE << " signed " << RESET << i9.getName() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}

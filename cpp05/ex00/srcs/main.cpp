#include "Bureaucrat.hpp"

void	createBureaucrat(std::string const name, int const grade)
{
	try
	{
		Bureaucrat bureaucrat(name, grade);
		std::cout << bureaucrat << LGREEN " created" RESET << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

int	main(void)
{
	std::cout << WBLUE << "Tests Bureaucrat limits ---------------------------------------- #" RESET << std::endl;

	// OK :
	createBureaucrat("Jean", 104);
	createBureaucrat("Julie", 56);

	// Grade too high :
	createBureaucrat("Phil", 0);
	createBureaucrat("Phil", -6);
	
	// Grade too low :
	createBureaucrat("Laura", 151);
	createBureaucrat("Laura", 2000);
	
	std::cout << WBLUE << "Tests copy/assign. --------------------------------------------- #" RESET << std::endl;

	// Copy and assignment :
	Bureaucrat paul("Paul", 5);
	Bureaucrat anna("Anna", 145);
	std::cout << paul << LGREEN " created" RESET << std::endl;
	std::cout << anna << LGREEN " created" RESET << std::endl;
	Bureaucrat paul2(paul);
	std::cout << paul2 << LGREEN " created" RESET << std::endl;
	paul2 = anna;
	std::cout << paul2 << LGREEN " assigned" RESET << std::endl;

	std::cout << WBLUE << "Tests in/decrementation ---------------------------------------- #" RESET << std::endl;

	// Increment :
	int i = 1;
	while (i > 0)
	{
		try
		{
			paul.incrementGrade();
			std::cout << paul << LBLUE " has been promoted !" RESET << std::endl;
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
			i = -1;
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
			i = -1;
		}
	}

	// Decrement :
	i = 1;
	while (i > 0)
	{
		try
		{
			anna.decrementGrade();
			std::cout << anna << ORANGE " has been downgraded !" RESET << std::endl;
		}
		catch (Bureaucrat::GradeTooHighException &e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
			i = -1;
		}
		catch (Bureaucrat::GradeTooLowException &e)
		{
			std::cout << RED << e.what() << RESET << std::endl;
			i = -1;
		}
	}

	return (0);
}

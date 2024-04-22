#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

void	createCopyAssignShrubberyCreationForm(void)
{
	std::cout << WBLUE << "Test copy and assign. --------------------------------------- #" RESET << std::endl;
	
	// Instantiate
	ShrubberyCreationForm scf1("oak");
	std::cout << scf1;
	std::cout << "|" << std::setw(20) << "Target:            " << "|" << std::setw(15) << scf1.getTarget() << "|";
	std::cout << LGREEN " created" RESET << std::endl;
	std::cout << "+--------------------+---------------+" << std::endl;

	ShrubberyCreationForm scf2("palmtree");
	std::cout << scf2;
	std::cout << "|" << std::setw(20) << "Target:            " << "|" << std::setw(15) << scf2.getTarget() << "|";
	std::cout << LGREEN " created" RESET << std::endl;
	std::cout << "+--------------------+---------------+" << std::endl;

	// Copy
	ShrubberyCreationForm scf3(scf1);
	std::cout << scf3;
	std::cout << "|" << std::setw(20) << "Target:            " << "|" << std::setw(15) << scf3.getTarget() << "|";
	std::cout << LGREEN " created" RESET << std::endl;
	std::cout << "+--------------------+---------------+" << std::endl;

	// Assign
	scf3 = scf2;
	std::cout << scf3;
	std::cout << "|" << std::setw(20) << "Target:            " << "|" << std::setw(15) << scf3.getTarget() << "|";
	std::cout << LGREEN " after assignment" RESET << std::endl;
	std::cout << "+--------------------+---------------+" << std::endl;

	std::cout << std::endl;
}

void	execShrubberyCreationForm(void)
{
	std::cout << WBLUE << "Test signature and exec ------------------------------------- #" RESET << std::endl;

	Bureaucrat president("Mr President", 137);
	Bureaucrat stateadmin("State admin", 145);
	Bureaucrat someguy("Some guy", 146);

	ShrubberyCreationForm scf1("oak");

	someguy.executeForm(scf1);
	someguy.signForm(scf1);
	stateadmin.signForm(scf1);
	stateadmin.executeForm(scf1);
	president.signForm(scf1);
	president.executeForm(scf1); // first exec
	president.executeForm(scf1); // second exec

	std::cout << std::endl;
}

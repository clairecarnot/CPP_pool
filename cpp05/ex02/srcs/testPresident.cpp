#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

void	createCopyAssignPresident(void)
{
	std::cout << WBLUE << "Test copy and assign. --------------------------------------- #" RESET << std::endl;
	
	// Instantiate
	PresidentialPardonForm ppf1("Billy the Kid");
	std::cout << ppf1;
	std::cout << "|" << std::setw(20) << "Target:            " << "|" << std::setw(15) << ppf1.getTarget() << "|";
	std::cout << LGREEN " created" RESET << std::endl;
	std::cout << "+--------------------+---------------+" << std::endl;

	PresidentialPardonForm ppf2("Calamity Jane");
	std::cout << ppf2;
	std::cout << "|" << std::setw(20) << "Target:            " << "|" << std::setw(15) << ppf2.getTarget() << "|";
	std::cout << LGREEN " created" RESET << std::endl;
	std::cout << "+--------------------+---------------+" << std::endl;

	// Copy
	PresidentialPardonForm ppf3(ppf1);
	std::cout << ppf3;
	std::cout << "|" << std::setw(20) << "Target:            " << "|" << std::setw(15) << ppf3.getTarget() << "|";
	std::cout << LGREEN " created" RESET << std::endl;
	std::cout << "+--------------------+---------------+" << std::endl;

	// Assign
	ppf3 = ppf2;
	std::cout << ppf3;
	std::cout << "|" << std::setw(20) << "Target:            " << "|" << std::setw(15) << ppf3.getTarget() << "|";
	std::cout << LGREEN " after assignment" RESET << std::endl;
	std::cout << "+--------------------+---------------+" << std::endl;

	std::cout << std::endl;
}

void	execPresident(void)
{
	std::cout << WBLUE << "Test signature and exec ------------------------------------- #" RESET << std::endl;

	Bureaucrat president("Mr President", 5);
	Bureaucrat stateadmin("State admin", 25);
	Bureaucrat someguy("Some guy", 26);

	PresidentialPardonForm ppf1("Billy the Kid");

	someguy.executeForm(ppf1);
	someguy.signForm(ppf1);
	stateadmin.signForm(ppf1);
	stateadmin.executeForm(ppf1);
	president.signForm(ppf1);
	president.executeForm(ppf1);

	std::cout << std::endl;
}

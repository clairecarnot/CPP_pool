#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"

void	createCopyAssignRobotomy(void)
{
	std::cout << WBLUE << "Test copy and assign. --------------------------------------- #" RESET << std::endl;
	
	// Instantiate
	RobotomyRequestForm rrf1("Topsecret file");
	std::cout << rrf1;
	std::cout << "|" << std::setw(20) << "Target:            " << "|" << std::setw(15) << rrf1.getTarget() << "|";
	std::cout << LGREEN " created" RESET << std::endl;
	std::cout << "+--------------------+---------------+" << std::endl;

	RobotomyRequestForm rrf2("Papers");
	std::cout << rrf2;
	std::cout << "|" << std::setw(20) << "Target:            " << "|" << std::setw(15) << rrf2.getTarget() << "|";
	std::cout << LGREEN " created" RESET << std::endl;
	std::cout << "+--------------------+---------------+" << std::endl;

	// Copy
	RobotomyRequestForm rrf3(rrf1);
	std::cout << rrf3;
	std::cout << "|" << std::setw(20) << "Target:            " << "|" << std::setw(15) << rrf3.getTarget() << "|";
	std::cout << LGREEN " created" RESET << std::endl;
	std::cout << "+--------------------+---------------+" << std::endl;

	// Assign
	rrf3 = rrf2;
	std::cout << rrf3;
	std::cout << "|" << std::setw(20) << "Target:            " << "|" << std::setw(15) << rrf3.getTarget() << "|";
	std::cout << LGREEN " after assignment" RESET << std::endl;
	std::cout << "+--------------------+---------------+" << std::endl;

	std::cout << std::endl;
}

void	execRobotomy(void)
{
	std::cout << WBLUE << "Test signature and exec ------------------------------------- #" RESET << std::endl;
	
	Bureaucrat president("Mr President", 45);
	Bureaucrat stateadmin("State admin", 46);
	Bureaucrat someguy("Some guy",73);

	RobotomyRequestForm rrf1("Topsecret file");

	someguy.executeForm(rrf1);
	someguy.signForm(rrf1);
	stateadmin.signForm(rrf1);
	stateadmin.executeForm(rrf1);
	president.signForm(rrf1);
	president.executeForm(rrf1);

	std::cout << std::endl;
}

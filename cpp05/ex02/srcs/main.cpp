#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void	createCopyAssignPresident(void);
void	execPresident(void);
void	createCopyAssignRobotomy(void);
void	execRobotomy(void);
void	createCopyAssignShrubberyCreationForm(void);
void	execShrubberyCreationForm(void);

int	main(void)
{
	// President pardon form tests
	std::cout << PURPLE "TESTS ON PRESIDENT PARDON FORM" RESET << std::endl;
	createCopyAssignPresident();
	execPresident();

	// Robotomy request form tests
	std::cout << PURPLE "TESTS ON ROBOTOMY REQUEST FORM" RESET << std::endl;
	createCopyAssignRobotomy();
	execRobotomy();

	// Shrubbery creation form tests
	std::cout << PURPLE "TESTS ON SHRUBBERY CREATION FORM" RESET << std::endl;
	createCopyAssignShrubberyCreationForm();
	execShrubberyCreationForm();

	return (0);
}

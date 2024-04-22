#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class	Bureaucrat ;
class	AForm ;
class	ShrubberyCreationForm;
class 	RobotomyRequestForm;
class	PresidentialPardonForm;

class	Intern
{
	public:
		Intern(void);
		Intern(Intern const &src);
		~Intern(void);

		Intern	&operator=(Intern const &src);

		AForm	*createSCF(std::string const &target);
		AForm	*createRRF(std::string const &target);
		AForm	*createPPF(std::string const &target);
		AForm	*makeForm(std::string const &name, std::string const &target);

		class	UnexistingFormException : public std::exception
		{
			public:
				virtual const char*	what() const throw()
				{
					return ("Intern could not create this kind of form because it does not exist!");
				}
		};
};


#endif

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <cstdlib>
# include <ctime>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class	Bureaucrat ;
class	AForm ;

class	RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(RobotomyRequestForm const &src);
		virtual ~RobotomyRequestForm(void);

		RobotomyRequestForm	&operator=(RobotomyRequestForm const &src);

		std::string		getTarget(void) const;

		virtual void		doExecute(void) const;

	private:
		std::string	_target;
};

#endif

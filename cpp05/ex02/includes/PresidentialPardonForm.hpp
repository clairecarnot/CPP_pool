#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"

class	Bureaucrat ;
class	AForm ;

class	PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(PresidentialPardonForm const &src);
		virtual ~PresidentialPardonForm(void);

		PresidentialPardonForm	&operator=(PresidentialPardonForm const &src);

		std::string		getTarget(void) const;

		virtual void		doExecute(void) const;

	private:
		std::string	_target;
};

#endif

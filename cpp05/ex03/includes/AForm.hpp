#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <iomanip>
# include "Bureaucrat.hpp"

class	Bureaucrat ;

class	AForm
{
	public:
		AForm(void);
		AForm(std::string const &name, int const sG, int const eG);
		AForm(AForm const &src);
		virtual ~AForm(void);

		AForm	&operator=(AForm const &src);

		std::string	getName(void) const;
		bool		getSignStatus(void) const;
		int		getSignGrade(void) const;
		int		getExecGrade(void) const;

		void		beSigned(Bureaucrat const &bur);
		void		execute(Bureaucrat const &executor) const;
		virtual void	doExecute(void) const = 0;


		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char *	what() const throw()
				{
					return ("grade is too high !");
				};
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char *	what() const throw()
				{
					return ("grade is too low !");
				};
		};

		class	AlreadySignedException : public std::exception
		{
			public:
				virtual const char *	what() const throw()
				{
					return ("form is already signed !");
				};
		};

		class	FormNotSignedException : public std::exception
		{
			public:
				virtual const char*	what() const throw()
				{
					return ("form is not signed !");
				}
		};

	private:
		std::string const	_name;
		bool			_signStatus;
		int const		_signGrade;
		int const		_execGrade;
};

std::ostream	&operator<<(std::ostream &os, AForm const &src);

#endif

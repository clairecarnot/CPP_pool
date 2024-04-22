#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <iomanip>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
{
	public:
		Form(void);
		Form(std::string const &name, int const sG, int const eG);
		Form(Form const &src);
		~Form(void);

		Form	&operator=(Form const &src);

		std::string	getName(void) const;
		bool		getSignStatus(void) const;
		int		getSignGrade(void) const;
		int		getExecGrade(void) const;

		void		beSigned(Bureaucrat const &bur);

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

	private:
		std::string const	_name;
		bool			_signStatus;
		int const		_signGrade;
		int const		_execGrade;
};

std::ostream	&operator<<(std::ostream &os, Form const &src);

#endif

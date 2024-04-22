#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Colors.hpp"

class	Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat(void);

		Bureaucrat	&operator=(Bureaucrat const &src);

		std::string	getName(void) const;
		int		getGrade(void) const;

		void		incrementGrade(void);
		void		decrementGrade(void);

		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char*	what() const throw()
				{
					return ("Grade is too high !");
				}
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char*	what() const throw()
				{
					return ("Grade is too low !");
				}
		};

	private:
		std::string const	_name;
		int			_grade;
};

std::ostream	&operator<<(std::ostream &os, Bureaucrat const &src);

#endif

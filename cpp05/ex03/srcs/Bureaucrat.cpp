#include "Bureaucrat.hpp"

// CONSTRUCTORS / DESTRUCTORS -------------------------------------------------------------- //

Bureaucrat::Bureaucrat(void) : _name("Buro"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name), _grade(src._grade)
{
}

Bureaucrat::~Bureaucrat(void)
{
}

// OPERATORS ------------------------------------------------------------------------------- //

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &src)
{
	if (this != &src)
		this->_grade = src._grade;
	return (*this);
}

// GETTERS / SETTERS ----------------------------------------------------------------------- //

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

// FUNCTIONS ------------------------------------------------------------------------------- //

void	Bureaucrat::incrementGrade(void)
{
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

void	Bureaucrat::decrementGrade(void)
{
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

void	Bureaucrat::signForm(AForm &f) const
{
	try
	{
		f.beSigned(*this);
		std::cout << this->getName() << LBLUE " signed " RESET << f.getName() << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout << this->getName() << ORANGE " couldn't sign " RESET << f.getName() << " because " << e.what() << std::endl;
	}
	catch (AForm::AlreadySignedException &e)
	{
		std::cout << this->getName() << ORANGE " couldn't sign " RESET << f.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &f) const
{
	try
	{
		f.execute(*this);
		std::cout << this->getName() << LBLUE " executed " RESET << f.getName() << std::endl;
	}
	catch (AForm::FormNotSignedException &e)
	{
		std::cout << this->getName() << ORANGE " couldn't execute " RESET << f.getName() << " because " << e.what() << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout << this->getName() << ORANGE " couldn't execute " RESET << f.getName() << " because " << e.what() << std::endl;
	}
}

// STATIC ELEMENTS ------------------------------------------------------------------------- //

std::ostream	&operator<<(std::ostream &os, Bureaucrat const &src)
{
	os << src.getName() << ", bureaucrat grade " << src.getGrade();
	return (os);
}

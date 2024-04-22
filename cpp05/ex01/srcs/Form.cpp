#include "Form.hpp"

// CONSTRUCTORS / DESTRUCTORS -------------------------------------------------------------- //

Form::Form(void) : _name("somePaper"), _signStatus(false), _signGrade(150), _execGrade(150)
{
}

Form::Form(std::string const &name, int const sG, int const eG) : _name(name), _signStatus(false), _signGrade(sG), _execGrade(eG)
{
	if (sG < 1 || eG < 1)
		throw GradeTooHighException();
	else if (sG > 150 || eG > 150)
		throw GradeTooLowException();
	else
		return ;
}

Form::Form(Form const &src) : _name(src._name), _signStatus(src._signStatus), _signGrade(src._signGrade), _execGrade(src._execGrade)
{
}

Form::~Form(void)
{
}

// OPERATORS ------------------------------------------------------------------------------- //

Form	&Form::operator=(Form const &src)
{
	if (this != &src)
		this->_signStatus = src._signStatus;
	return (*this);
}

// GETTERS / SETTERS ----------------------------------------------------------------------- //

std::string	Form::getName(void) const
{
	return (this->_name);
}

bool		Form::getSignStatus(void) const
{
	return (this->_signStatus);
}

int		Form::getSignGrade(void) const
{
	return (this->_signGrade);
}

int		Form::getExecGrade(void) const
{
	return (this->_execGrade);
}

// FUNCTIONS ------------------------------------------------------------------------------- //

void	Form::beSigned(Bureaucrat const &bur)
{
	if (this->getSignStatus())
		throw AlreadySignedException();
	else if (bur.getGrade() > this->getSignGrade())
		throw GradeTooLowException();
	else
		this->_signStatus = true;
}

// STATIC ELEMENTS ------------------------------------------------------------------------- //

std::ostream	&operator<<(std::ostream &os, Form const &src)
{
	/*
	os << "Form " << src.getName() << ":" << std::endl << "Signature status: " << src.getSignStatus() << std::endl << "Signature grade: " << src.getSignGrade() << std::endl << "Execution grade: " << src.getExecGrade();*/
	os << "Form " << src.getName() << ":" << std::endl;
	os << "+--------------------+---------------+" << std::endl;
	os << "|" << std::setw(20) << "Signature status   " << "|" << std::setw(15) << src.getSignStatus() << "|" << std::endl;
	os << "+--------------------+---------------+" << std::endl;
	os << "|" << std::setw(20) << "Signature grade    " << "|" << std::setw(15) << src.getSignGrade() << "|" << std::endl;
	os << "+--------------------+---------------+" << std::endl;
	os << "|" << std::setw(20) << "Execution grade    " << "|" << std::setw(15) << src.getExecGrade() << "|" << std::endl;
	os << "+--------------------+---------------+";
	return (os);
}

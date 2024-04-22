#include "AForm.hpp"

// CONSTRUCTORS / DESTRUCTORS -------------------------------------------------------------- //

AForm::AForm(void) : _name("somePaper"), _signStatus(false), _signGrade(150), _execGrade(150)
{
}

AForm::AForm(std::string const &name, int const sG, int const eG) : _name(name), _signStatus(false), _signGrade(sG), _execGrade(eG)
{
	if (sG < 1 || eG < 1)
		throw GradeTooHighException();
	else if (sG > 150 || eG > 150)
		throw GradeTooLowException();
	else
		return ;
}

AForm::AForm(AForm const &src) : _name(src._name), _signStatus(src._signStatus), _signGrade(src._signGrade), _execGrade(src._execGrade)
{
}

AForm::~AForm(void)
{
}

// OPERATORS ------------------------------------------------------------------------------- //

AForm	&AForm::operator=(AForm const &src)
{
	if (this != &src)
		return (*this);
	return (*this);
}

// GETTERS / SETTERS ----------------------------------------------------------------------- //

std::string	AForm::getName(void) const
{
	return (this->_name);
}

bool		AForm::getSignStatus(void) const
{
	return (this->_signStatus);
}

int		AForm::getSignGrade(void) const
{
	return (this->_signGrade);
}

int		AForm::getExecGrade(void) const
{
	return (this->_execGrade);
}

// FUNCTIONS ------------------------------------------------------------------------------- //

void	AForm::beSigned(Bureaucrat const &bur)
{
	if (this->getSignStatus())
		throw AlreadySignedException();
	else if (bur.getGrade() > this->getSignGrade())
		throw GradeTooLowException();
	else
		this->_signStatus = true;
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSignStatus())
		throw FormNotSignedException();
	else if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	else
		doExecute();
}

// STATIC ELEMENTS ------------------------------------------------------------------------- //

std::ostream	&operator<<(std::ostream &os, AForm const &src)
{
	os << "Form " << src.getName() << ":" << std::endl;
	os << "+--------------------+---------------+" << std::endl;
	os << "|" << std::setw(20) << "Signature status   " << "|" << std::setw(15) << src.getSignStatus() << "|" << std::endl;
	os << "+--------------------+---------------+" << std::endl;
	os << "|" << std::setw(20) << "Signature grade    " << "|" << std::setw(15) << src.getSignGrade() << "|" << std::endl;
	os << "+--------------------+---------------+" << std::endl;
	os << "|" << std::setw(20) << "Execution grade    " << "|" << std::setw(15) << src.getExecGrade() << "|" << std::endl;
	os << "+--------------------+---------------+" << std::endl;
	return (os);
}

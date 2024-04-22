#include "ShrubberyCreationForm.hpp"

// CONSTRUCTORS / DESTRUCTORS -------------------------------------------------------------- //

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("Shrubbery Creation", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm("Shrubbery Creation", 145, 137), _target(src._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

// OPERATORS ------------------------------------------------------------------------------- //

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src)
{
	if (this != &src)
		this->_target = src._target;
	return (*this);
}

// GETTERS / SETTERS ----------------------------------------------------------------------- //

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

// FUNCTIONS ------------------------------------------------------------------------------- //

void	ShrubberyCreationForm::doExecute(void) const
{
	std::string	filename = this->_target + "_shrubbery";
	std::string	tree("               ,@@@@@@@,\n");
	tree += "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
	tree += "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
	tree += "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n";
	tree += "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n";
	tree += "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n";
	tree += "   `&%\\ ` /%&'    |.|        \\ '|8'\n";
	tree += "       |o|        | |         | |\n";
	tree += "       |.|        | |         | |\n";
	tree += "jgs \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n";
	std::ofstream	of(filename.c_str(), std::ios::app);
	if (!of)
	{
		std::cout << "Error: failed to open new file" << std::endl;
		return ;
	}
	else
	{
		of << tree << std::endl;
	}
}

// STATIC ELEMENTS ------------------------------------------------------------------------- //


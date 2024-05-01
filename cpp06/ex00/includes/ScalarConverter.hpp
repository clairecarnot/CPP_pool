#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

bool	isLim(std::string const &input);
bool	isChar(std::string const &input);
bool	isInt(std::string const &input);
bool	isFloat(std::string const &input);
bool	isDouble(std::string const &input);

void	convertLim(std::string const &input);
void	convertAsChar(std::string const &input);
void	convertAsInt(std::string const &input);
void	convertAsFloat(std::string const &input);
void	convertAsDouble(std::string const &input);

class	ScalarConverter
{
	public:
		static void	convert(std::string const &input);

	private:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &src);
		~ScalarConverter(void);

		ScalarConverter	&operator=(ScalarConverter const &src);
};

#endif

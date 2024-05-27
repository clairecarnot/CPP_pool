#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <iomanip>
# include <fstream>
# include <map>
# include <sstream>
# include <string>
# include <cctype>
# include <limits>

class	BitcoinExchange
{
	public:
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const &src);
		~BitcoinExchange(void);

		BitcoinExchange	&operator=(BitcoinExchange const &src);

		std::map<std::string, float> const	&getDb(void) const;

		void	checkAnd_display(std::string const &input);

		class	CouldNotOpenFileException : public std::exception
		{
			public:
				virtual const char*	what(void) const throw()
				{
					return ("Error : could not open database file.");
				}
		};

		class	BadInputException : public std::exception
		{
			public:
				virtual const char*	what(void) const throw()
				{
					return ("Error : bad input => ");
				}
		};

		class	NbNegativeException : public std::exception
		{
			public:
				virtual const char*	what(void) const throw()
				{
					return ("Error : not a positive number.");
				}
		};

		class	NbTooLargeException : public std::exception
		{
			public:
				virtual const char*	what(void) const throw()
				{
					return ("Error : too large a number.");
				}
		};

	private:
		std::map<std::string, float>	_db;

		void	_checkDateErrors(std::string const &date);
		void	_checkValueErrors(std::string const &value);
		void	_checkSepErrors(std::string const &sep, std::string const &input);
		void	_display(std::string const &date, std::string const &value);
};

#endif

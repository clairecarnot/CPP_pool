#include "BitcoinExchange.hpp"

// CONSTRUCTOR / DESTRUCTOR --------------------------------------------------- //

BitcoinExchange::BitcoinExchange(void)
{
	std::string const	filename("data.csv");
	std::string		date;
	std::string		value;
	float			fvalue;

	std::ifstream	is(filename.c_str());
	if (is)
	{
		std::getline(is, date);
		while (std::getline(is, date, ','))
		{
			std::getline(is, value); 
			std::istringstream iss(value);
			iss >> fvalue;
			this->_db[date] = fvalue;
		}
	}
	else
		throw (CouldNotOpenFileException());
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) : _db(src._db)
{
}

BitcoinExchange::~BitcoinExchange(void)
{
}

// OPERATORS ------------------------------------------------------------------ //

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &src)
{
	if (this != &src)
		this->_db = src._db;
	return (*this);
}

// GETTERS / SETTERS ---------------------------------------------------------- //

std::map<std::string, float> const	&BitcoinExchange::getDb(void) const
{
	return (this->_db);
}

// FUNCTIONS ------------------------------------------------------------------ //

void	BitcoinExchange::_checkDateErrors(std::string const &date)
{
	int	year, month, day;

	if (date.empty() || date.size() != 10)
		throw BitcoinExchange::BadInputException();
	if (date[4] != '-' || date[7] != '-')
		throw BitcoinExchange::BadInputException();

	std::istringstream	iss(date);

	iss >> year;
	if (year < 2009 || year > 2022)
		throw BitcoinExchange::BadInputException();

	iss.ignore();
	iss >> month;
	if (month < 1 || month > 12)
		throw BitcoinExchange::BadInputException();

	iss.ignore();
	iss >> day;
	if (day < 1 || day > 31)
		throw BitcoinExchange::BadInputException();

	if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31)
		throw BitcoinExchange::BadInputException();
	if (year == 2009 && month == 1 && day < 2)
		throw BitcoinExchange::BadInputException();
	if (year > 2022 || (year == 2022 && month > 3) || (year == 2022 && month == 3 
				&& day > 29))
		throw BitcoinExchange::BadInputException();
	if (month == 2 && day > 28)
	{
		if (day > 29)
			throw BitcoinExchange::BadInputException();
		if (day == 29 && (year % 4) != 0)
			throw BitcoinExchange::BadInputException();
	}
}

void	BitcoinExchange::_checkValueErrors(std::string const &value)
{
	float	number;
	int	i = 0;

	if (!std::isdigit(value[i]) && value[i] != '-')
		throw BitcoinExchange::BadInputException();
	if (value[i] == '-')
	{
		if (value[i + 1])
			i++;
		else
			throw BitcoinExchange::BadInputException();
	}
	while (value[i] && value[i] != '.')
	{
		if (value[i] < '0' || value[i] > '9')
			throw BitcoinExchange::BadInputException();
		i++;
	}
	if (value[i] && value[i] == '.')
	{
		if (value[i + 1])
			i++;
		else
			throw BitcoinExchange::BadInputException();
		while (value[i])
		{
			if (value[i] < '0' || value[i] > '9')
				throw BitcoinExchange::BadInputException();
			i++;
		}
	}

	std::istringstream	iss(value);
	iss >> number;
	if (iss.fail())
	{
		if (number == std::numeric_limits<float>::infinity())
			throw BitcoinExchange::NbTooLargeException();
		if (number == -std::numeric_limits<float>::infinity())
			throw BitcoinExchange::NbNegativeException();
	}
	if (number < 0)
		throw BitcoinExchange::NbNegativeException();
	if (number > 1000)
		throw BitcoinExchange::NbTooLargeException();
}

void	BitcoinExchange::_checkSepErrors(std::string const &sep, std::string const &input)
{
	int	spaces = 0;

	for (std::size_t i = 0; i < input.size(); ++i)
	{
		if (input[i] == ' ')
			spaces++;
	}
	if (spaces != 2 || sep != "|")
		throw BitcoinExchange::BadInputException();
}

void	BitcoinExchange::_display(std::string const &date, std::string const &value)
{
	float			fvalue;
	std::istringstream	iss(value);
	iss >> fvalue;

	std::map<std::string, float>::const_iterator it = this->_db.upper_bound(date);
	if (it->first != date && it != _db.begin())
		it--;
	std::cout << date << " => " << value << " = " << it->second * fvalue << std::endl;
}

void	BitcoinExchange::checkAnd_display(std::string const &input)
{
	std::string		date, sep, value;
	std::istringstream	iss(input);

	iss >> date >> sep >> value;
	try
	{
		_checkDateErrors(date);
		_checkValueErrors(value);
		_checkSepErrors(sep, input);
		
		_display(date, value);
	}
	catch (BitcoinExchange::BitcoinExchange::BadInputException &e)
	{
		std::cout << e.what() << input << std::endl;
	}
	catch (BitcoinExchange::BitcoinExchange::NbNegativeException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (BitcoinExchange::BitcoinExchange::NbTooLargeException &e)
	{
		std::cout << e.what() << std::endl;
	}
}

// STATIC ELEMENTS ------------------------------------------------------------ //



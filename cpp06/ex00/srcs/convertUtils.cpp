# include <iostream>
# include <cctype>
# include <sstream>
# include <limits>

// Identify received type -----------------------------------------------------//

bool	isLim(std::string const &input)
{
	if (input == "-inff" || input == "+inff" || input == "-inf"
		|| input == "+inf" || input == "nan" || input == "nanf")
		return (true);
	else
		return (false);
}

bool	isChar(std::string const &input)
{
	if (input.length() == 1 && isalpha(input[0]))
		return (true);
	else
		return (false);
}

bool	isInt(std::string const &input)
{
	int i = 0;
	if (input[i] && (input[i] == '+' || input[i] == '-'))
		i++;
	while (input[i])
	{
		if (input[i] < '0' || input[i] > '9')
			return (false);
		i++;
	}

	std::istringstream is(input);
	int value;
	is >> value;
	if (is.fail())
		return (false);
	else
		return (true);
}

bool	isFloat(std::string const &input)
{
	int i = 0;
	if (input[i] && (input[i] == '+' || input[i] == '-'))
		i++;
	while (input[i] && input[i] != '.')
	{
		if (input[i] < '0' || input[i] > '9')
			return (false);
		i++;
	}
	if (input[i] && input[i] == '.' && input[i + 1])
		i++;
	else
		return (false);
	while (input[i] && input[i] != 'f')
	{
		if (input[i] < '0' || input[i] > '9')
			return (false);
		i++;
	}
	if (!input[i] || input[i] != 'f' || input[i + 1])
		return (false);

	std::istringstream is(input);
	float value;
	is >> value;

	if (is.fail())
		return (false);
	else
		return (true);
}

bool	isDouble(std::string const &input)
{
	int i = 0;
	if (input[i] && (input[i] == '+' || input[i] == '-'))
		i++;
	while (input[i] && input[i] != '.')
	{
		if (input[i] < '0' || input[i] > '9')
			return (false);
		i++;
	}
	if (input[i] && input[i] == '.' && input[i + 1])
		i++;
	else
		return (false);
	while (input[i])
	{
		if (input[i] < '0' || input[i] > '9')
			return (false);
		i++;
	}

	std::istringstream is(input);
	double value;
	is >> value;
	if (is.fail())
		return (false);
	else
		return (true);
}

// Cast and print types -------------------------------------------------------//

void	convertLim(std::string const &input)
{
	//	std::cout << "Convert as Lim" << std::endl;
	std::cout << "char : impossible" << std::endl;
	std::cout << "int : impossible" << std::endl;

	if (input == "nan" || input == "nanf")
	{
		std::cout << "float : nanf" << std::endl;
		std::cout << "double : nan" << std::endl;
	}
	else if (input == "+inf" || input == "+inff")
	{
		std::cout << "float : +inff" << std::endl;
		std::cout << "double : +inf" << std::endl;
	}
	else
	{
		std::cout << "float : -inff" << std::endl;
		std::cout << "double : -inf" << std::endl;
	}
}

void	convertAsChar(std::string const &input)
{
	//	std::cout << "Convert as Char" << std::endl;
	if (!isprint(input[0]))
	{
		std::cout << "char : is char but non-printable" << std::endl;
		std::cout << "int : " << static_cast<int>(input[0]) << std::endl;
		std::cout << "float : " << static_cast<float>(input[0]) << ".0f" << std::endl;
		std::cout << "double : " << static_cast<double>(input[0]) << ".0" << std::endl;
	}
	else
	{
		std::cout << "char : " << "'" << input[0] << "'" << std::endl;
		std::cout << "int : " << static_cast<int>(input[0]) << std::endl;
		std::cout << "float : " << static_cast<float>(input[0]) << ".0f" << std::endl;
		std::cout << "double : " << static_cast<double>(input[0]) << ".0" << std::endl;
	}
}

void	convertAsInt(std::string const &input)
{
	//	std::cout << "Convert as Int" << std::endl;
	std::istringstream is(input);
	int value;
	is >> value;

	//	char:
	if (value >= 32 && value <= 126)
		std::cout << "char : " << "'" << static_cast<char>(value) << "'" << std::endl;
	else if ((value >= 0 && value < 32) || value == 127)
		std::cout << "char : is char but non-printable" << std::endl;
	else
		std::cout << "char : impossible" << std::endl;

	//	int:
	std::cout << "int : " << value << std::endl;

	//	float:
	std::cout << "float : " << static_cast<float>(value) << ".0f" << std::endl;

	//	double:
	std::cout << "double : " << static_cast<double>(value) << ".0" << std::endl;
}

void	convertAsFloat(std::string const &input)
{
	//	std::cout << "Convert as Float" << std::endl;
	std::istringstream is(input);
	float value;
	is >> value;

	//	char:
	if (value >= 32 && value <= 126)
		std::cout << "char : " << "'" << static_cast<char>(value) << "'" << std::endl;
	else if ((value >= 0 && value < 32) || value == 127)
		std::cout << "char : is char but non-printable" << std::endl;
	else
		std::cout << "char : impossible" << std::endl;

	//	int:
	if (value >= static_cast<float>(std::numeric_limits<int>::min())
			&& value < static_cast<float>(std::numeric_limits<int>::max()))
		std::cout << "int : " << static_cast<int>(value) << std::endl;
	else
		std::cout << "int : impossible" << std::endl;

	//	float:
	if (value == static_cast<int>(value))
		std::cout << "float : " << value << ".0f" << std::endl;
	else
		std::cout << "float : " << value << "f" << std::endl;

	//	double:
	if (value == static_cast<int>(value))
		std::cout << "double : " << static_cast<double>(value) << ".0" << std::endl;
	else
		std::cout << "double : " << static_cast<double>(value) << std::endl;
}

void	convertAsDouble(std::string const &input)
{
	//	std::cout << "Convert as Double" << std::endl;
	std::istringstream is(input);
	double value;
	is >> value;

	//	char:
	if (value >= 32 && value <= 126)
		std::cout << "char : " << "'" << static_cast<char>(value) << "'" << std::endl;
	else if ((value >= 0 && value < 32) || value == 127)
		std::cout << "char : is char but non-printable" << std::endl;
	else
		std::cout << "char : impossible" << std::endl;

	//	int:
	if (value >= static_cast<double>(std::numeric_limits<int>::min())
			&& value < static_cast<double>(std::numeric_limits<int>::max()))
		std::cout << "int : " << static_cast<int>(value) << std::endl;
	else
		std::cout << "int : impossible" << std::endl;

	//	float:
	if (value >= -static_cast<double>(std::numeric_limits<float>::max())
			&& value < static_cast<double>(std::numeric_limits<float>::max()))
	{
		if (value == static_cast<int>(value))
			std::cout << "float : " << static_cast<float>(value) << ".0f" << std::endl;
		else
			std::cout << "float : " << static_cast<float>(value) << "f" << std::endl;
	}
	else
		std::cout << "float : impossible" << std::endl;

	//	double:
	if (value == static_cast<int>(value))
		std::cout << "double : " << value << ".0" << std::endl;
	else
		std::cout << "double : " << value << std::endl;
}

// Notes: FLOAT min
// La dynamique c'est la fourchette de valeurs couverte par le codage là on va de 10+38 à 10-38
// 3.4028235E+38
// La résolution c'est le plus petit pas entre 2 valeurs consécutives: 6 (ou 7) décimales
// 1.175494e-38
// "Si une opération travaillant avec des flottants dépasse la capacité du type du résultat, alors, comme pour les entiers signés, le comportement est indéfini.
// Toutefois, les flottants étant généralement représenté suivant la norme IEEE 754 (scientifique), le résultat sera souvent le suivant:
//     En cas de dépassement de la borne maximale ou minimale, le résultat sera égal à l’infini (positif ou négatif).
//     En cas de dépassement de la limite de la partie fractionnaire, le résultat sera arrondi à zéro."

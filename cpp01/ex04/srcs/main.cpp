#include <iostream>
#include <fstream>
#include <string>

bool	handleStringsErrors(std::string const s1, std::string const s2)
{
	if (s1.empty() || s2.empty() || !s1.length() || !s2.length())
	{
		std::cout << "Error" << std::endl
			<< "Strings must contain at least one char." << std::endl;
		return (false);
	}
	else
		return (true);
}

bool	doReplacement(std::ifstream &infile, std::ofstream &outfile, std::string &s1, std::string &s2)
{
	std::string	str;

	while (getline(infile, str))
	{
		std::string	result;
		std::size_t	found(0);
		std::size_t	lastPos(0);
		while (found != std::string::npos && found < str.length())
		{
			found = str.find(s1.c_str(), lastPos);
			if (found != std::string::npos && found < str.length())
			{
				result += str.substr(lastPos, found - lastPos);
				result += s2;
				found += s1.length();
				lastPos = found;
			}
			else
				result += str.substr(lastPos, str.length() - lastPos);
		}
		if (!infile.eof())
			result += "\n";
		outfile << result;
	}
	return (true);
}

/*
 * TESTS
 * ./stringReplace test1 amis copains	<normal>
 * ./stringReplace test2 amis copains	<normal>
 * ./stringReplace test3 a aa		<normal>
 * ./stringReplace test4 zzz Z		<rien a remplacer>
 * ./stringReplace test5 A Z		<normal>
 * ./stringReplace			<pas d'args>
 * ./stringReplace test3 a aa aaa	<trop d'args>
 * ./stringReplace test3 "" s2		<string vide>
 */

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Invalid number of arguments." << std::endl
			<< "Arguments should be:" << std::endl
			<< "./program <filename> <string1> <string2>" <<std::endl;
		return (1);
	}
	else
	{
		std::string	s1(argv[2]);
		std::string	s2(argv[3]);
		std::string	filename(argv[1]);
		if (!handleStringsErrors(s1, s2))
			return (1);

		std::ifstream infile(filename.c_str());
		if (!infile)
		{
			std::cout << "Infile stream failed opening" << std::endl;
			return (1);
		}

		std::ofstream outfile(filename.append(".replace").c_str());
		if (!outfile)
		{
			std::cout << "Outfile stream failed opening" << std::endl;
			return (1);
		}

		if (doReplacement(infile, outfile, s1, s2))
			return (0);
		else
			return (1);
	}
}

#include "Colors.hpp"
#include "ScalarConverter.hpp"

/*
int	main(int argc, char **argv)
{
	if (argc != 2)
		std::cout << "Error : invalid number of arguments." << std::endl;
	else
		ScalarConverter::convert(argv[1]);
	return (0);
}
*/

/*
int	main(void)
{
	std::cout << "./convert 0" << std::endl;
	ScalarConverter::convert("0");
	std::cout << std::endl;

	std::cout << "./convert nan" << std::endl;
	ScalarConverter::convert("nan");
	std::cout << std::endl;

	std::cout << "./convert 42.0f" << std::endl;
	ScalarConverter::convert("42.0f");
	std::cout << std::endl;

	return (0);
}
*/

int	main(void)
{
	std::cout << LBLUE "Test \"\"" RESET << std::endl;
	ScalarConverter::convert("");

	std::cout << LBLUE "Test \"1a\"" RESET << std::endl;
	ScalarConverter::convert("1a");

	std::cout << LBLUE "Test \"a1\"" RESET << std::endl;
	ScalarConverter::convert("a1");

	std::cout << LBLUE "Test \"a\"" RESET << std::endl;
	ScalarConverter::convert("a");

	std::cout << LBLUE "Test \"1\"" RESET << std::endl;
	ScalarConverter::convert("1");

	std::cout << LBLUE "Test \"88.0\"" RESET << std::endl;
	ScalarConverter::convert("88.0");

	std::cout << LBLUE "Test \"2147483648\"" RESET << std::endl;
	ScalarConverter::convert("2147483648");

	std::cout << LBLUE "Test \"2147483648.0\"" RESET << std::endl;
	ScalarConverter::convert("2147483648.0");

	std::cout << LBLUE "Test \"2147483648.9\"" RESET << std::endl;
	ScalarConverter::convert("2147483648.9");

	std::cout << LBLUE "Test \"2147483648.9f\"" RESET << std::endl;
	ScalarConverter::convert("2147483648.9f");

	std::cout << LBLUE "Test \"+4\"" RESET << std::endl;
	ScalarConverter::convert("+4");

	std::cout << LBLUE "Test \"++4\"" RESET << std::endl;
	ScalarConverter::convert("++4");

	std::cout << LBLUE "Test \"--4\"" RESET << std::endl;
	ScalarConverter::convert("--4");

	std::cout << LBLUE "Test \"2147483648..2f\"" RESET << std::endl;
	ScalarConverter::convert("2147483648..2f");

	std::cout << LBLUE "Test \"1.0\"" RESET << std::endl;
	ScalarConverter::convert("1.0");

	std::cout << LBLUE "Test \"1.0f\"" RESET << std::endl;
	ScalarConverter::convert("1.0f");

	std::cout << LBLUE "Test \"1.3f\"" RESET << std::endl;
	ScalarConverter::convert("1.3f");

	std::cout << LBLUE "Test \"1.3\"" RESET << std::endl;
	ScalarConverter::convert("1.3");

	std::cout << LBLUE "Test \"2147483649.03f\"" RESET << std::endl;
	ScalarConverter::convert("2147483649.03f");

	std::cout << LBLUE "Test min float \"-340282346638528859811704183484516925440.0f\"" RESET << std::endl;
	ScalarConverter::convert("-340282346638528859811704183484516925440.0f");

	std::cout << LBLUE "Test < min float \"-340282346638528859811704183484516925441.0f\"" RESET << std::endl;
	ScalarConverter::convert("-340282346638528859811704183484516925441.0f");

	std::cout << LBLUE "Test mindouble \"-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0\"" RESET << std::endl;
	ScalarConverter::convert("-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0");

	std::cout << LBLUE "Test <mindouble \"-1797693134862315708145274237317043567980705675258449965989174768031572607800285387605895586327668781715404589535143824642343213268894641827684675467035375169860499105765512820762454900903893289440758685084551339423045832369032229481658085593321233482747978262041447231687381771809192998812504040261841248583689.0\"" RESET << std::endl;
	ScalarConverter::convert("-1797693134862315708145274237317043567980705675258449965989174768031572607800285387605895586327668781715404589535143824642343213268894641827684675467035375169860499105765512820762454900903893289440758685084551339423045832369032229481658085593321233482747978262041447231687381771809192998812504040261841248583689.0");

	return (0);
}

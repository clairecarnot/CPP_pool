#include "Colors.hpp"
#include "Array.hpp"

int	testSubject(void)
{
	std::cout << ABLUE "// Test from Subject ------------------------------------ // " RESET << std::endl;

	Array<int> numbers(MAX_VAL);

	int* mirror = new int[MAX_VAL];

	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}

	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}

	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}

	delete [] mirror;//

	std::cout << std::endl;
	
	return (0);
}

void	constFloatArray(void)
{
	std::cout << ABLUE "// Test Float const Array ------------------------------- // " RESET << std::endl;

	// Instanciation
	const Array <float> test(5);

	// Test a value
	std::cout << test[4]  << std::endl;

	// Test: should not compile because const
	// test[0] = 0;
	
	// Print Object Array
	std::cout << test  << std::endl;
	
	std::cout << std::endl;
}

void	intArray(void)
{
	std::cout << ABLUE "// Test Int Array --------------------------------------- // " RESET << std::endl;

	// Instanciation
	Array <int> test(5);
	test[0] = 0;
	test[1] = 1;
	test[2] = 2;
	test[3] = 3;
	test[4] = 4;

	// Test a value
	std::cout << test[3]  << std::endl;

	// Print Object Array
	std::cout << test  << std::endl;

	// Try to reach unavailable index
	try
	{
		std::cout << test[-1]  << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Could not read value because " << e.what() << std::endl;
	}
	
	std::cout << std::endl;
}

void	doubleArray(void)
{
	std::cout << ABLUE "// Test Double Array --------------------------------------- // " RESET << std::endl;

	// Instanciation
	Array <double> test(2);
	test[0] = 0.53;
	test[1] = 17.66;

	// Test a value
	std::cout << test[0]  << std::endl;

	// Print Object Array
	std::cout << test  << std::endl;

	// Try to reach unavailable index
	try
	{
		std::cout << test[2]  << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Could not read value because " << e.what() << std::endl;
	}
	
	std::cout << std::endl;
}

void	otherTests(void)
{
	std::cout << ABLUE "// Additional tests ---------------------------------------- // " RESET << std::endl;

	// Instanciation by default
	Array <double> test;

	// Instanciation by copy
	Array <float> test2(3);
	test2[0] = 5.55f;
	test2[1] = -12.3f;
	test2[2] = 1.02f;
	std::cout << test2  << std::endl;
	Array <float> test3(test2);
	std::cout << test3  << std::endl;

	// Assignment operator
	Array <int> test4(2);
	test4[0] = -3;
	test4[1] = 14;
	std::cout << test4 << std::endl;
	Array <int> test5;
	test5 = test4;
	std::cout << test5 << std::endl;
	Array <int> test6;
	test5 = test6;
	std::cout << test5 << std::endl;
}

int	main(void)
{
	testSubject();
	constFloatArray();
	intArray();
	doubleArray();
	otherTests();

	return (0);
}

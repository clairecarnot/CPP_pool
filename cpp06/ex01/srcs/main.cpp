#include "Colors.hpp"
#include "Serializer.hpp"

void	testHeap(void)
{
	std::cout << PURPLE "TEST: HEAP" RESET << std::endl;

	// 1
	Data *ptr1 = new Data;
	ptr1->nb = -10;
	std::cout << "ptr1 = " << ptr1 << std::endl;
	std::cout << "ptr1->nb = " << ptr1->nb << std::endl;

	// 2
	uintptr_t raw = Serializer::serialize(ptr1);
	std::cout << "raw = " << raw << std::endl;

	// 3
	Data *ptr2 = Serializer::deserialize(raw);
	std::cout << "ptr2 = " << ptr2 << std::endl;
	std::cout << "ptr2->nb = " << ptr2->nb << std::endl;
	
	delete ptr1;
}

void	testStack(void)
{
	std::cout << PURPLE "TEST: STACK" RESET << std::endl;

	// 1
	Data data;
	data.nb = 42;
	std::cout << "data = " << &data << std::endl;
	std::cout << "data->nb = " << data.nb << std::endl;

	// 2
	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "raw = " << raw << std::endl;

	// 3
	Data *ptr = Serializer::deserialize(raw);
	std::cout << "ptr = " << ptr << std::endl;
	std::cout << "ptr->nb = " << ptr->nb << std::endl;
}

int	main(void)
{
	testHeap();
	testStack();

	return (0);
}

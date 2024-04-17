#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

void	moreStaticTests(void)
{
	std::cout << " More tests <static mode> --------------------------------------" << std::endl;
	const WrongAnimal*	meta = new WrongCat();
	const WrongCat	*i = new WrongCat();

	std::cout << meta->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	meta->makeSound();
	i->makeSound();
	delete meta;
	delete i;
	std::cout << std::endl;
}

void	moreDynamicTests(void)
{
	std::cout << " More tests <dynamic mode> -------------------------------------" << std::endl;
	const Dog	*j = new Dog();
	const Cat	*i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	delete j;
	delete i;
	std::cout << std::endl;
}

void	staticTests(void)
{
	std::cout << " Tests from the subject <static mode> --------------------------" << std::endl;
	const WrongAnimal*	meta = new WrongAnimal();
	const Animal*	j = new Dog();
	const WrongAnimal*	i = new WrongCat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
	std::cout << std::endl;
}

void	dynamicTests(void)
{
	std::cout << " Tests from the subject <dynamic mode> -------------------------" << std::endl;
	const Animal*	meta = new Animal();
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
	std::cout << std::endl;
}

int	main(void)
{
	dynamicTests();
	staticTests();
	moreDynamicTests();
	moreStaticTests();
	return (0);
}

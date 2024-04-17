#include "AAnimal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

void	copyCatTest(void)
{
	std::cout << " Test : Copycat---------------------------------------------" << std::endl;
	const Cat	*cat = new Cat();

	cat->getBrain()->setIdeas(0, "\e[3;35mLook at these lazy Humans. I am so superior.\e[0m");
	cat->getBrain()->setIdeas(1, "\e[3;35mNow let's try to catch this flea.\e[0m");
	cat->getBrain()->setIdeas(2, "\e[3;35mSleep or eat ? That's the question.\e[0m");

	const Cat	*copy = new Cat(*cat);

	cat->getBrain()->setIdeas(0, "\e[3;35mDu dubadubadu dubadubadu duduuuuuuuu !\e[0m");
	cat->getBrain()->setIdeas(1, "\e[3;35m*Mentally puuuuurrrrrs*\e[0m");
	cat->getBrain()->setIdeas(2, "\e[3;35mMy best friend is my Tuna soup\e[0m");

	std::cout << copy->getBrain()->getIdeas(0) << std::endl;
	std::cout << copy->getBrain()->getIdeas(1) << std::endl;
	std::cout << copy->getBrain()->getIdeas(2) << std::endl;

	std::cout << cat->getBrain()->getIdeas(0) << std::endl;
	std::cout << cat->getBrain()->getIdeas(1) << std::endl;
	std::cout << cat->getBrain()->getIdeas(2) << std::endl;

	delete cat;
	delete copy;
	std::cout << std::endl;
}

void	copyDogTest(void)
{
	std::cout << " Test : Copydog---------------------------------------------" << std::endl;
	const Dog	*dog = new Dog();

	dog->getBrain()->setIdeas(0, "\e[3;36mEAAAAAAAAAAAAAT !!! EAT EAT EAT EAT EAT\e[0m");
	dog->getBrain()->setIdeas(1, "\e[3;36mPLAY ? PLAY PLAY PLAY PLAY PLAY PLAY\e[0m");
	dog->getBrain()->setIdeas(2, "\e[3;36mFRIEND ! FRIENDFRIENDFRIENDFRIEND\e[0m");

	const Dog	*copy = new Dog(*dog);

	dog->getBrain()->setIdeas(0, "\e[3;36mWhat ?! who is this stupid Dog ?\e[0m");
	dog->getBrain()->setIdeas(1, "\e[3;36mHave some dignity bro !\e[0m");
	dog->getBrain()->setIdeas(2, "\e[3;36m*Sighs* can I have a fork and knife for my meal ?\e[0m");

	std::cout << copy->getBrain()->getIdeas(0) << std::endl;
	std::cout << copy->getBrain()->getIdeas(1) << std::endl;
	std::cout << copy->getBrain()->getIdeas(2) << std::endl;

	std::cout << dog->getBrain()->getIdeas(0) << std::endl;
	std::cout << dog->getBrain()->getIdeas(1) << std::endl;
	std::cout << dog->getBrain()->getIdeas(2) << std::endl;

	delete dog;
	delete copy;
	std::cout << std::endl;
}

void	arrayTest(void)
{
	std::cout << " Test : array of 4 AAnimals ---------------------------------" << std::endl;
	// Array of 4 AAnimals
	AAnimal	*pets[4];

	for (int i = 0; i < 2; i++)
		pets[i] = new Dog();
	for (int i = 2; i < 4; i++)
		pets[i] = new Cat();
	for (int i = 0; i < 4; i++)
		(*pets[i]).makeSound();
	for (int i = 0; i < 4; i++)
		delete pets[i];
	std::cout << std::endl;
}

void	basicTest(void)
{
	std::cout << " Test from the subject --------------------------------------" << std::endl;
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	delete j;//should not create a leak
	delete i;
	std::cout << std::endl;
}

void	instantiationTest(void)
{
	// Below tests should not compile
// 	AAnimal	*meta = new AAnimal();
//	meta->makeSound();
//	delete meta;
}

int	main(void)
{
	basicTest();
	arrayTest();
	copyCatTest();
	copyDogTest();
	instantiationTest();
	return (0);
}

#include "../includes/Zombie.hpp"

void	randomChump(std::string name);
Zombie	*newZombie(std::string name);

int	main(void)
{
	Zombie *zombie = newZombie("\e[35mPif\e[0m");
	zombie->announce();

	randomChump("\e[35mPaf\e[0m");

	delete zombie;

	return (0);
}

#include "../includes/Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

int	 main(void)
{
	int		N(10);
	std::string name("\e[35mZombinos\e[0m");

	Zombie *horde = zombieHorde(N, name);
	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete [] horde;

	return (0);
}

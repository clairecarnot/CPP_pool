#include "../includes/Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	Zombie	*newZ;

	newZ = new Zombie(name);
	return (newZ);
}

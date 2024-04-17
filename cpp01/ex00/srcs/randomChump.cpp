#include "../includes/Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie rChump(name);
	rChump.announce();
	return ;
}

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap pif("Pif");
	ScavTrap paf("Paf");
	ScavTrap pouf("Pouf");
	ScavTrap copy(pouf);

	std::cout << std::endl << "ROUND 1 ----------------------------------------------------------" << std::endl;

	pif.setAttackDamages(30);
	pif.attack(paf.getName());
	paf.takeDamage(pif.getAttackDamages());

	std::cout << "ROUND 2 ----------------------------------------------------------" << std::endl;
	paf.attack(pif.getName());
	pif.takeDamage(paf.getAttackDamages());
	pif.attack(paf.getName());
	paf.beRepaired(10);
	pouf.attack(pif.getName());
	pif.takeDamage(pouf.getAttackDamages());

	std::cout << "ROUND 3 ----------------------------------------------------------" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		pouf.attack(paf.getName());
		paf.takeDamage(pouf.getAttackDamages());
	}

	paf.attack(pouf.getName());

	pouf.guardGate();

	return (0);
}

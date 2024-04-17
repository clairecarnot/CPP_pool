#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap pif("Pif");
	ClapTrap paf("Paf");
	ClapTrap pouf("Pouf");
	ClapTrap copy(pif);

	std::cout << std::endl << "ROUND 1 ----------------------------------------------------------" << std::endl;
	pif.attack(paf.getName());
	paf.takeDamage(pif.getAttackDamages());

	std::cout << "ROUND 2 ----------------------------------------------------------" << std::endl;
	pif.setAttackDamages(1);
	paf.setAttackDamages(6);
	pouf.setAttackDamages(10);

	for (int i = 0; i < 9; i++)
	{
		pif.attack(paf.getName());
		paf.takeDamage(pif.getAttackDamages());
	}

	std::cout << "ROUND 3 ----------------------------------------------------------" << std::endl;
	pif.attack(paf.getName());
	paf.attack(pif.getName());
	pif.takeDamage(paf.getAttackDamages());
	pif.beRepaired(10);
	paf.attack(pif.getName());
	pif.takeDamage(paf.getAttackDamages());
	pif.attack(paf.getName());
	pif.beRepaired(10);

	std::cout << "ROUND 4 ----------------------------------------------------------" << std::endl;
	pouf.attack(pif.getName());
	pif.takeDamage(pouf.getAttackDamages());
	pouf.attack(paf.getName());
	paf.takeDamage(pouf.getAttackDamages());

	return (0);
}

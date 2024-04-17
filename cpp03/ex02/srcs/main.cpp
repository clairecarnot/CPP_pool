#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap pif("Pif");
	ScavTrap paf("Paf");
	FragTrap pouf("Pouf");
	FragTrap bim("Bim");
	FragTrap copy(bim);

	std::cout << std::endl << "ROUND 1 ----------------------------------------------------------" << std::endl;

	pif.setAttackDamages(90);
	pif.attack(paf.getName());
	paf.takeDamage(pif.getAttackDamages());

	paf.guardGate();

	pif.attack(pouf.getName());
	pouf.takeDamage(pif.getAttackDamages());

	std::cout << "ROUND 2 ----------------------------------------------------------" << std::endl;
	pouf.attack(pif.getName());
	pif.takeDamage(pouf.getAttackDamages());
	pif.attack(paf.getName());

	pouf.attack(paf.getName());
	paf.takeDamage(pouf.getAttackDamages());
	paf.attack(paf.getName());

	std::cout << "ROUND 3 ----------------------------------------------------------" << std::endl;
	pouf.beRepaired(10);
	bim.attack(pouf.getName());
	pouf.takeDamage(bim.getAttackDamages());

	pouf.attack(bim.getName());
	pouf.beRepaired(10);

	bim.attack(pouf.getName());
	pouf.takeDamage(bim.getAttackDamages());

	bim.highFivesGuys();

	return (0);
}

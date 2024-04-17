#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	ClapTrap pif("Pif");
	ScavTrap paf("Paf");
	FragTrap pouf("Pouf");
	DiamondTrap bim("Bim");
	DiamondTrap bam("Bam");
	DiamondTrap copy(bam);

	std::cout << std::endl << "ROUND 1 ----------------------------------------------------------" << std::endl;

	pif.setAttackDamages(90);

	pif.attack(paf.getName());
	paf.takeDamage(pif.getAttackDamages());

	pif.attack(pouf.getName());
	pouf.takeDamage(pif.getAttackDamages());

	pif.attack(bim.getName());
	bim.takeDamage(pif.getAttackDamages());

	bim.beRepaired(10);
	bim.guardGate();
	bim.highFivesGuys();
	bim.whoAmI();

	std::cout << "ROUND 2 ----------------------------------------------------------" << std::endl;
	bim.attack(pif.getName());
	pif.takeDamage(bim.getAttackDamages());

	bim.attack(paf.getName());
	paf.takeDamage(bim.getAttackDamages());

	bam.attack(bim.getName());
	bim.takeDamage(bam.getAttackDamages());

	bim.attack(bam.getName());
	bim.beRepaired(10);

	bam.whoAmI();

	return (0);
}

#include "Colors.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

// Tests on class Character
void	testCharacter(void)
{
	std::cout << BOLD WBLUE "# TESTS ON CHARACTER" RESET << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");

	std::cout << LBLUE "// Tests - equip & inventory:" RESET << std::endl;
	AMateria* tmp;
	me->equip(src->createMateria("ice")); // first equipment
	dynamic_cast<Character *>(me)->printInventory();
	me->equip(src->createMateria("ice"));
	me->equip(src->createMateria("cure"));
	me->equip(src->createMateria("cure")); // fourth equipment
	dynamic_cast<Character *>(me)->printInventory();
	tmp = src->createMateria("cure");
	me->equip(tmp); // inventory already full
	delete tmp;

	std::cout << LBLUE "// Tests - drop to and pick from floor:" RESET << std::endl;
	AMateria const* dropped1;
	AMateria const* dropped2;
	AMateria const* dropped3;
	dropped1 = dynamic_cast<Character *>(me)->droppedMateria(1); // first object on the floor
	me->unequip(1); // unequips
	dropped2 = dynamic_cast<Character *>(me)->droppedMateria(2);
	me->unequip(2);
	dropped3 = dynamic_cast<Character *>(me)->droppedMateria(2); //slot already empty - nothing happens
	me->unequip(2); // slot already empty
	me->equip(src->createMateria(dropped2->getType()));
	dynamic_cast<Character *>(me)->printInventory();
	delete dropped1;
	delete dropped2;

	std::cout << LBLUE "// Tests - using equipments:" RESET << std::endl;
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(-3, *bob);
	me->use(5, *bob);
	delete bob;
	delete me;

	std::cout << LBLUE "// Tests - assignment & copy :" RESET << std::endl;
	Character *bing = new Character("Bing");
	bing->equip(src->createMateria("ice"));
	bing->equip(src->createMateria("ice"));
	bing->equip(src->createMateria("ice"));
	bing->equip(src->createMateria("ice"));
	Character *plouf = new Character(*bing); // copy constructor
	Character *vroum = new Character("Vroum");
	std::cout << "Character vroum's name is : " << vroum->getName() << std::endl;
	*vroum = *plouf; // assignment operator
	dynamic_cast<Character *>(vroum)->printInventory();
	std::cout << "Character vroum's name is : " << vroum->getName() << std::endl;
	delete src;
	delete bing;
	delete plouf;
	delete vroum;

	std::cout << std::endl;
}

// Tests on Materia classes
void	testMateria(void)
{
	// Should not compile
	// AMateria *am = new AMateria();

	std::cout << BOLD WBLUE "# TESTS ON MATERIA" RESET << std::endl;
	std::cout << LBLUE "// Tests - copy and assignment :" RESET << std::endl;
	AMateria *ice = new Ice();
	AMateria *cure = new Cure();
	std::cout << "Ice has a type : " << ice->getType() << std::endl;
	std::cout << "Cure has a type : " << cure->getType() << std::endl;
	*ice = *cure; // assignment operator
	std::cout << "Ice has a type : " << ice->getType() << std::endl;
	std::cout << "Cure has a type : " << cure->getType() << std::endl;
	delete ice;
	delete cure;

	Cure *c1 = new Cure();
	Cure *c2 = new Cure(*c1); //copy constructor
	Cure *c3 = new Cure();
	*c3 = *c1; // assignment operator
	std::cout << "c1 has a type : " << c1->getType() << std::endl;
	std::cout << "c2 has a type : " << c2->getType() << std::endl;
	std::cout << "c3 has a type : " << c3->getType() << std::endl;
	delete c1;
	delete c2;
	delete c3;

	Ice *i1 = new Ice();
	Ice *i2 = new Ice(*i1); // copy contructor
	Ice *i3 = new Ice();
	*i3 = *i1; // assignment operator
	std::cout << "i1 has a type : " << i1->getType() << std::endl;
	std::cout << "i2 has a type : " << i2->getType() << std::endl;
	std::cout << "i3 has a type : " << i3->getType() << std::endl;
	delete i1;
	delete i2;
	delete i3;

	std::cout << std::endl;
}

// Tests on class MateriaSource
void	testMateriaSource(void)
{
	std::cout << BOLD WBLUE "# TESTS ON MATERIASOURCE" RESET << std::endl;
	std::cout << LBLUE "// Tests - inventory:" RESET << std::endl;
	IMateriaSource* ms = new MateriaSource();
	dynamic_cast<MateriaSource *>(ms)->printTemplates();
	ms->learnMateria(new Ice()); // first template added
	dynamic_cast<MateriaSource *>(ms)->printTemplates();
	ms->learnMateria(new Cure());
	ms->learnMateria(new Ice());
	ms->learnMateria(new Cure()); // fourth template added
	dynamic_cast<MateriaSource *>(ms)->printTemplates();
	Cure *cure = new Cure();
	ms->learnMateria(cure); // four templates already - no more addings
	delete cure;
	delete ms;

	std::cout << LBLUE "// Tests - copy and assignment:" RESET << std::endl;
	MateriaSource* ms1 = new MateriaSource();
	ms1->learnMateria(new Cure());
	ms1->learnMateria(new Cure());
	MateriaSource* ms2 = new MateriaSource(*ms1); // copy constructor
	MateriaSource* ms3 = new MateriaSource();
	*ms3 = *ms2; // assignment operator
	ms3->printTemplates();
	delete ms1;
	delete ms2;
	delete ms3;

	std::cout << LBLUE "// Tests - create unexisting materia :" RESET << std::endl;
	AMateria* tmp;
	MateriaSource* ms4 = new MateriaSource();
	ms4->learnMateria(NULL); // unexisting materia - does nothing
	ms4->learnMateria(new Cure());
	tmp = ms4->createMateria("ice"); // materia does not exist
	delete ms4;

	std::cout << std::endl;
}

// Tests from the subject
void	testSubject(void)
{
	std::cout << BOLD WBLUE "# SUBJECT TESTS" RESET << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	std::cout << std::endl;
}

int	main(void)
{
	testSubject();
	testMateriaSource();
	testMateria();
	testCharacter();
	return (0);
}

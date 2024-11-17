#include <IMateriaSource.h>
#include <MateriaSource.h>
#include <Character.h>
#include <Ice.h>
#include <Cure.h>

int main(void)
{
	MateriaSource *src = new MateriaSource();
	IMateriaSource* rrr = new MateriaSource(*src);

	rrr->createMateria("ice");
	rrr->createMateria("dfgsd"); //			try to create a wrong materia
	rrr->learnMateria(new Ice());
	rrr->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria* tmp = NULL;

	Character aaaa("yaaaa");

	aaaa.equip(tmp);
	src->learnMateria(new Ice());
	tmp = src->createMateria("ice"); //		try to equip 2 times the same materia
	aaaa.equip(tmp);
	aaaa.equip(tmp);

	aaaa.unequip(0);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = rrr->createMateria("ice");
	me->equip(tmp);
	tmp = rrr->createMateria("cure");
	me->equip(tmp);
	tmp = rrr->createMateria("cure");
	me->equip(tmp);
	tmp = rrr->createMateria("cure"); //	try to equip a fifth materia
	me->equip(tmp);
	delete tmp;

	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	bob->use(999, *me);
	bob->use(0, *me);

	delete me;
	delete bob;
	delete src;
	delete rrr;
	return 0;
}

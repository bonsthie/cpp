#include "ICharacter.h"
#include <Cure.h>
#include <iostream>

const std::string Cure::_typeNameMateria(void) { return ("cure"); }

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

#include "ICharacter.h"
#include <Ice.h>
#include <iostream>

const std::string Ice::_typeNameMateria(void) { return ("ice"); }

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

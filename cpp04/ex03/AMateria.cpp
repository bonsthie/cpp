#include "ICharacter.h"
#include <AMateria.h>
#include <iostream>
#include <log.h>
#include <string>

AMateria::AMateria(std::string const &type) : _type(type) {
  LOG("AMateria name constructor " + _type);
}

AMateria::AMateria(const AMateria &origin) {
  *this = origin;
  LOG("AMateria by reference constructor " + _type);
}

AMateria::AMateria(void) : _type("default") {
  LOG("AMateria default constructor " + _type);
}

AMateria::~AMateria(void) { LOG("AMateria destructor"); }

const std::string &AMateria::getType(void) const { return (_type); }

/* void AMateria::use(ICharacter &origin) { */
/*   std::cout << "default use " << origin.getName() << std::endl; */
/* } */

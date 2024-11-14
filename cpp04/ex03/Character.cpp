#include "ICharacter.h"
#include "log.h"
#include <Character.h>
#include <cstring>
#include <iostream>

Character::Character(void) : _name("default") {
  LOG("Character default constructor " + _name)
  memset(static_cast<void *>(_materia), 0, sizeof(_materia));
}

Character::Character(const std::string &name) : _name(name) {
  LOG("Character name constructor " + _name)
  memset(static_cast<void *>(_materia), 0, sizeof(_materia));
}

Character::Character(const Character &origin) {
  LOG("Character by reference constructor " + _name)
  *this = origin;
}

Character::~Character(void) {
  LOG("Character destructor " + _name)
  for (int i = 0; i < CHARACTER_MATERIA_SIZE; i++) {
    if (_materia[i].ptr)
		delete _materia[i].ptr;
  }
}

const std::string &Character::getName() const { return (_name); }

void Character::equip(AMateria *m) {
  if (!m)
    return;
  for (int i = 0; i < CHARACTER_MATERIA_SIZE; i++) {
	if (m == _materia[i].ptr) {
		std::cout << "materia already equip" << std::endl;
		return ;
	}
    if (_materia[i].ptr == NULL) {
      _materia[i].ptr = m;
      return;
    }
  }
  std::cout << "you can't equip more AMateria" << std::endl;
}

void Character::unequip(int idx) {
  if (idx >= CHARACTER_MATERIA_SIZE || idx < 0)
    return;
  _materia[idx].unequip = true;
}

void Character::use(int idx, ICharacter &target) {
  if (idx >= CHARACTER_MATERIA_SIZE || idx < 0)
    return;
  if (_materia[idx].ptr == NULL || _materia[idx].unequip == true)
    return;
  _materia[idx].ptr->use(target);
}

Character Character::operator=(const Character &origin) {
  if (this != &origin) {
    for (int i = 0; i < CHARACTER_MATERIA_SIZE; i++) {
      if (_materia[i].ptr != NULL) {
        delete (_materia[i].ptr);
        _materia[i].ptr = NULL;
      }
      if (origin._materia[i].ptr == NULL)
        continue;
      _materia[i].ptr = origin._materia[i].ptr->clone();
      _materia[i].unequip = origin._materia[i].unequip;
    }
    _name = origin._name;
  }
  return (*this);
}

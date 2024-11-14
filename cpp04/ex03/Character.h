
#pragma once

#include "AMateria.h"
#include <ICharacter.h>

#define CHARACTER_MATERIA_SIZE 4

class Character : public ICharacter {
public:
  Character(const std::string &name);
  Character(const Character &origin);
  Character(void);
  ~Character(void);

  std::string const &getName() const;
  void equip(AMateria *m);
  void unequip(int idx);
  void use(int idx, ICharacter &target);

  Character operator=(const Character &origin);

private:
  std::string _name;
  struct {
    AMateria *ptr;
    bool unequip;
  } _materia[CHARACTER_MATERIA_SIZE];
};

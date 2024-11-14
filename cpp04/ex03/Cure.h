#pragma once

#include "ICharacter.h"
#include <MateriaTemplate.h>

class Cure : public MateriaTemplate<Cure> {
public:
  void use(ICharacter &target);

  static const std::string _typeNameMateria(void);
};

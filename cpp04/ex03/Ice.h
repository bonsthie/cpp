#pragma once

#include "ICharacter.h"
#include <MateriaTemplate.h>

class Ice : public MateriaTemplate<Ice> {
public:
  void use(ICharacter &target);

  static const std::string _typeNameMateria(void);
};

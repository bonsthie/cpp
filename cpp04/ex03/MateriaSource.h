#pragma once

#include "AMateria.h"
#include <IMateriaSource.h>

#define MS_COUNT 4

class MateriaSource : public IMateriaSource {
public:
  ~MateriaSource();

  void learnMateria(AMateria *);
  AMateria *createMateria(std::string const &type);

private:
  AMateria *_materia[MS_COUNT];
};

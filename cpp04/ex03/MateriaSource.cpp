#include <MateriaSource.h>
#include <iostream>
#include <log.h>

MateriaSource::~MateriaSource(void) {
  LOG("MateriaSource destructor");
  for (int i = 0; i < MS_COUNT; i++) {
    if (_materia[i] != NULL)
      delete _materia[i];
  }
}

void MateriaSource::learnMateria(AMateria *m) {
  if (!m)
    return;
  for (int i = 0; i < MS_COUNT; i++) {
    if (_materia[i] == NULL) {
      _materia[i] = m;
      return;
    }
  }
  std::cout << "you can't learn more AMateria" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type) {
  for (int i = 0; i < MS_COUNT; i++) {
    if (_materia[i] && type.compare(_materia[i]->getType()) == 0) {
      void *ptr = _materia[i]->clone();
      return (AMateria *)ptr;
    }
  }
  return NULL;
}


#pragma once

#include <AMateria.h>
#include <log.h>

template <typename T>
class MateriaTemplate : public AMateria {
public:
  MateriaTemplate(const T &origin);
  MateriaTemplate(void);
  virtual ~MateriaTemplate(void);

  T &operator=(const T &origin);

  AMateria *clone(void) const;

};

template <typename T>
MateriaTemplate<T>::MateriaTemplate(const T &origin) {
  *this = origin;
  LOG(T::_typeNameMateria() + " by reference constructor");
}

template <typename T>
MateriaTemplate<T>::MateriaTemplate(void) {
  this->_type = T::_typeNameMateria();
  LOG(T::_typeNameMateria() + " default constructor");
}

template <typename T>
MateriaTemplate<T>::~MateriaTemplate(void) { LOG(T::_typeNameMateria() + " destructor"); }

template <typename T>
T &MateriaTemplate<T>::operator=(const T &origin) {
	if (this != &origin) {
		this->_type = origin._type;
	}
	return (*this);
}

template <typename T>
AMateria *MateriaTemplate<T>::clone(void) const {
	return (new T);
}


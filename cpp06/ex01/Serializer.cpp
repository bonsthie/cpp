#include "Serializer.h"
#include "log.h"

Serializer::Serializer(void){LOG("constructor Serializer empty")}

Serializer::Serializer(const Serializer &src) {
  LOG("constructor Serializer copy")
  if (this != &src)
    *this = src;
}

Serializer::~Serializer(void){LOG("destructor Serializer")}

Data *Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data *>(raw));
}

uintptr_t Serializer::serialize(Data *data) {
	return (reinterpret_cast<uintptr_t>(data));
}

Serializer &Serializer::operator=(Serializer const &src) {
  if (this == &src)
    return (*this);
  return (*this);
}

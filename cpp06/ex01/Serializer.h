#pragma once

#include <stdint.h>

struct Data {
  uintptr_t foo;
};

class Serializer {
public:
  uintptr_t serialize(Data *ptr);
  Data* deserialize(uintptr_t raw);

  Serializer(void);
  ~Serializer(void);
private:
  Serializer(const Serializer &ref);

  Serializer &operator=(Serializer const &src);
};

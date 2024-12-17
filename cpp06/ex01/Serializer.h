#pragma once

#include <stdint.h>

struct Data {
  uintptr_t foo;
};

class Serializer {
public:
  static uintptr_t serialize(Data *ptr);
  static Data* deserialize(uintptr_t raw);

private:
  Serializer(void);
  ~Serializer(void);

  Serializer(const Serializer &ref);

  Serializer &operator=(Serializer const &src);
};

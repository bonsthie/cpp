#include "aaaaa.h"
#include "log.h"

aaaaa::aaaaa(void) {
  LOG("constructor aaaaa empty")
}

aaaaa::aaaaa(const aaaaa &src) {
  LOG("constructor aaaaa copy")
  if (this != &src)
    *this = src;
}

aaaaa::~aaaaa(void) {
  LOG("destructor aaaaa")
}

aaaaa &aaaaa::operator=(aaaaa const &src) {
  if (this == &src)
    return (*this);
  return (*this);
}
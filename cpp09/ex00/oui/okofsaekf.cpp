#include "okofsaekf.h"
#include "log.h"

okofsaekf::okofsaekf(void) {
  LOG("constructor okofsaekf empty")
}

okofsaekf::okofsaekf(const okofsaekf &src) {
  LOG("constructor okofsaekf copy")
  if (this != &src)
    *this = src;
}

okofsaekf::~okofsaekf(void) {
  LOG("destructor okofsaekf")
}

okofsaekf &okofsaekf::operator=(okofsaekf const &src) {
  if (this == &src)
    return (*this);
  return (*this);
}
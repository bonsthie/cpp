#pragma once

#include <string>

class ICharacter;

class AMateria {
public:
  AMateria(std::string const &type);
  AMateria(const AMateria &origin);
  AMateria(void);
  virtual ~AMateria(void);

  std::string const &getType() const;
  virtual AMateria *clone(void) const = 0;
  virtual void use(ICharacter &target) = 0;

protected:
  std::string _type;

};

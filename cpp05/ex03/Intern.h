#pragma once

#include "AForm.h"

class Intern {
  public:
    Intern(const Intern &ref);
    Intern(void);
    ~Intern(void);

    AForm *makeForm(const std::string target, const std::string name) const;

    Intern &operator=(Intern const &src);
};

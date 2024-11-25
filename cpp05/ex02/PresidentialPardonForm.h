#pragma once

#include "AForm.h"

class PresidentialPardonForm : public AForm {
  public:
    PresidentialPardonForm(const PresidentialPardonForm &ref);
    PresidentialPardonForm(const std::string &name);
    PresidentialPardonForm(void);
    ~PresidentialPardonForm(void);

    PresidentialPardonForm &operator=(PresidentialPardonForm const &src);
private:
	void _interExecute(const Bureaucrat &b) const;
};

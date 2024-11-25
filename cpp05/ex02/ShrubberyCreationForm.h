#pragma once

#include "AForm.h"
#include "ErrClassTemplate.h"

class ShrubberyCreationForm : public AForm {
  public:
    ShrubberyCreationForm(const ShrubberyCreationForm &ref);
    ShrubberyCreationForm(const std::string &name);
    ShrubberyCreationForm(void);
    ~ShrubberyCreationForm(void);

    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &src);

	ERR_CLASS(openFileFailed)
private:
	void _interExecute(const Bureaucrat &b) const;
};

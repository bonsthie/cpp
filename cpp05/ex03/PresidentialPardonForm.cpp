#include "PresidentialPardonForm.h"
#include "log.h"

#define MIN_SIGN 25
#define MIN_EXEC 5

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
    : AForm(src) {
    LOG("constructor PresidentialPardonForm copy")
    if (this != &src)
        *this = src;
}

PresidentialPardonForm::~PresidentialPardonForm(void){
    LOG("destructor PresidentialPardonForm")}

PresidentialPardonForm &PresidentialPardonForm::operator=(
    PresidentialPardonForm const &src) {
    if (this == &src)
        return (*this);
    return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(void)
    : AForm("default_shrubbery", MIN_SIGN, MIN_EXEC) {
    LOG("constructor PresidentialPardonForm empty")
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &name)
    : AForm(name, MIN_SIGN, MIN_EXEC) {
    LOG("constructor PresidentialPardonForm empty")
}

void PresidentialPardonForm::_interExecute(const Bureaucrat &b) const {
	 std::cout << b << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

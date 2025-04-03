#include "RobotomyRequestForm.h"
#include "log.h"
#include <cstdlib>

#define MIN_SIGN 72
#define MIN_EXEC 45

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
    : AForm(src) {
    LOG("constructor RobotomyRequestForm copy")
    if (this != &src)
        *this = src;
}

RobotomyRequestForm::~RobotomyRequestForm(void){
    LOG("destructor RobotomyRequestForm")}

RobotomyRequestForm &RobotomyRequestForm::operator=(
    RobotomyRequestForm const &) {
    return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(void)
    : AForm("default_shrubbery", MIN_SIGN,
            MIN_EXEC){LOG("constructor RobotomyRequestForm empty")}

      RobotomyRequestForm::RobotomyRequestForm(const std::string &name)
    : AForm(name, MIN_SIGN, MIN_EXEC) {
    LOG("constructor RobotomyRequestForm empty")
}

void RobotomyRequestForm::_interExecute(const Bureaucrat &b) const {
    std::cout << "Drilling noises..." << std::endl;
    srand(time(0));
    if (rand() % 2 == 0) {
        std::cout << b << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "Robotomy failed on " << b << "." << std::endl;
    }
}

#include "AForm.h"
#include "Bureaucrat.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"
#include <exception>

#define SPACE std::cout << "\n\n\n";

int main() {
    try {
        Bureaucrat no("no", 150);
        Bureaucrat yes("yes", 130);

        AForm *yes_form = new ShrubberyCreationForm("yes to yes");

        no.executeForm(*yes_form);
        yes.executeForm(*yes_form);

        no.signForm(*yes_form);
        yes.signForm(*yes_form);

        no.executeForm(*yes_form);
        yes.executeForm(*yes_form);

        delete yes_form;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

	SPACE

    try {
        Bureaucrat yes("yes", 1);

        AForm *yes_form = new RobotomyRequestForm("yes to yes");
        yes.signForm(*yes_form);

        yes.executeForm(*yes_form);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

	SPACE

    try {
        Bureaucrat yes("yes", 1);

        AForm *yes_form = new PresidentialPardonForm("yes to yes");
        yes.signForm(*yes_form);

        yes.executeForm(*yes_form);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

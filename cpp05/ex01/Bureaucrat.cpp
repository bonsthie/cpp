#include "Bureaucrat.h"
#include "ErrClassTemplate.h"
#include "Form.h"
#include "log.h"
#include <exception>

/* constructor / destructor */

Bureaucrat::Bureaucrat(void){LOG("constructor Bureaucrat empty")}

Bureaucrat::Bureaucrat(const Bureaucrat &src) {
    LOG("constructor Bureaucrat copy")
    if (this != &src)
        *this = src;
}

Bureaucrat::~Bureaucrat(void){LOG("destructor Bureaucrat")}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
    : _name(name) {
    LOG("constructor Bureaucrat name/grade")
    if (grade > LOWESTGRADE)
        throw GradeTooLowException();
    if (grade < HIGHESTGRADE)
        throw GradeTooHighException();
    _grade = grade;
}

/* getter */

const std::string &Bureaucrat::getName() const { return _name; }
int                Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::incrementGrade() { (*this)++; }

void Bureaucrat::decrementGrade() { (*this)--; }

void Bureaucrat::signForm(Form &form) {
	try
	{
		form.beSign(*this);
		std::cout << *this << " signed " << form << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << *this << " couldn’t sign " << form << " because : " << e.what() << std::endl;
	 }

}

/* operator */

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src) {
    if (this == &src)
        return (*this);
    _grade = src.getGrade();
    return (*this);
}

Bureaucrat &Bureaucrat::operator++(void) {
    _grade--;
    if (_grade < HIGHESTGRADE)
        throw GradeTooHighException();
    return (*this);
}

Bureaucrat Bureaucrat::operator++(int) {
    Bureaucrat old = *this;
    _grade--;
    if (_grade < HIGHESTGRADE)
        throw GradeTooHighException();
    return (old);
}

Bureaucrat &Bureaucrat::operator--(void) {
    _grade++;
    if (_grade > LOWESTGRADE)
        throw GradeTooLowException();
    return (*this);
}
Bureaucrat Bureaucrat::operator--(int) {
    Bureaucrat old = *this;
    _grade++;
    if (_grade > LOWESTGRADE)
        throw GradeTooLowException();
    return (old);
}

std::ostream &operator<<(std::ostream &oStream, Bureaucrat &value) {
    oStream << value.getName() << " bureaucrat grade " << value.getGrade()
            << ".";
    return (oStream);
}

/* error throw */

ERR_WHAT(Bureaucrat, GradeTooLowException, "Bureaucrat grade too low")
ERR_WHAT(Bureaucrat, GradeTooHighException, "Bureaucrat grade too high")

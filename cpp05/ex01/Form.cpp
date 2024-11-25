#include "Form.h"
#include "Bureaucrat.h"
#include "ErrClassTemplate.h"
#include "log.h"

/* constuctor/destructor */

Form::Form(const std::string &name, int minimumGradeSign,
           int minimumGradeExecute)
    : _name(name),
      _minimumGradeSign(minimumGradeSign),
      _minimumGradeExecute(minimumGradeExecute) {
    LOG("constructor Form")
    _checkGrade();
}

Form::Form(const Form &src)
    : _minimumGradeSign(src.GetMinimumGradeSign()),
      _minimumGradeExecute(src.GetMinimumGradeExecute()) {
    LOG("constructor Form copy")
    if (this != &src)
        *this = src;
    _checkGrade();
}

Form::~Form(void){LOG("destructor Form")}

Form &Form::operator=(Form const &src) {
    if (this == &src)
        return (*this);
    _isSigned = src.GetIsSigned();
    _name = src.GetName();
    return (*this);
}

Form::Form(void)
    : _name("default"),
      _isSigned(false),
      _minimumGradeSign(LOWESTGRADE),
      _minimumGradeExecute(LOWESTGRADE) {
    LOG("constructor Form empty")
}

/* getter */

const std::string &Form::GetName() const { return _name; }
bool               Form::GetIsSigned() const { return _isSigned; }
int Form::GetMinimumGradeSign() const { return _minimumGradeSign; }
int Form::GetMinimumGradeExecute() const { return _minimumGradeExecute; }

void Form::beSign(const Bureaucrat &b) {
    if (b.getGrade() > _minimumGradeSign)
        throw GradeTooLowException();
    _isSigned = true;
}

void Form::_checkGrade() const {
    if (_minimumGradeSign > LOWESTGRADE || _minimumGradeExecute > LOWESTGRADE)
        throw GradeTooLowException();
    if (_minimumGradeSign < HIGHESTGRADE || _minimumGradeExecute < HIGHESTGRADE)
        throw GradeTooHighException();
}

std::ostream &operator<<(std::ostream &o, const Form &a) {
    o << "Form: " << a.GetName() << " (sign: " << a.GetMinimumGradeSign()
      << ", exec: " << a.GetMinimumGradeExecute() << ")";
    return o;
}

ERR_WHAT(Form, GradeTooLowException, "Form grade too low")
ERR_WHAT(Form, GradeTooHighException, "Form grade too high")

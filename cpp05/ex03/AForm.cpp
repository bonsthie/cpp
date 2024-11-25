#include "AForm.h"
#include "Bureaucrat.h"
#include "ErrClassTemplate.h"
#include "log.h"

/* constuctor/destructor */

AForm::AForm(const std::string &name, int minimumGradeSign,
           int minimumGradeExecute)
    : _name(name),
      _minimumGradeSign(minimumGradeSign),
      _minimumGradeExecute(minimumGradeExecute) {
    LOG("constructor AForm")
    _checkGrade();
}

AForm::AForm(const AForm &src)
    : _minimumGradeSign(src.GetMinimumGradeSign()),
      _minimumGradeExecute(src.GetMinimumGradeExecute()) {
    LOG("constructor AForm copy")
    if (this != &src)
        *this = src;
    _checkGrade();
}

AForm::~AForm(void){LOG("destructor AForm")}

AForm &AForm::operator=(AForm const &src) {
    if (this == &src)
        return (*this);
    _isSigned = src.GetIsSigned();
    _name = src.GetName();
    return (*this);
}

AForm::AForm(void)
    : _name("default"),
      _isSigned(false),
      _minimumGradeSign(LOWESTGRADE),
      _minimumGradeExecute(LOWESTGRADE) {
    LOG("constructor AForm empty")
}

/* getter */

const std::string &AForm::GetName() const { return _name; }
bool               AForm::GetIsSigned() const { return _isSigned; }
int AForm::GetMinimumGradeSign() const { return _minimumGradeSign; }
int AForm::GetMinimumGradeExecute() const { return _minimumGradeExecute; }

void AForm::beSigned(const Bureaucrat &b) {
    if (b.getGrade() > _minimumGradeSign)
        throw GradeTooLowException();
    _isSigned = true;
}

void AForm::execute(const Bureaucrat &b) const {
	if (_isSigned == false)
		throw FormNotSign();
	if (b.getGrade() > _minimumGradeExecute)
		throw GradeTooLowException();
	_interExecute(b);
}

void AForm::_checkGrade() const {
    if (_minimumGradeSign > LOWESTGRADE || _minimumGradeExecute > LOWESTGRADE)
        throw GradeTooLowException();
    if (_minimumGradeSign < HIGHESTGRADE || _minimumGradeExecute < HIGHESTGRADE)
        throw GradeTooHighException();
}

std::ostream &operator<<(std::ostream &o, const AForm &a) {
    o << "AForm: " << a.GetName() << " (sign: " << a.GetMinimumGradeSign()
      << ", exec: " << a.GetMinimumGradeExecute() << ")";
    return o;
}

ERR_WHAT(AForm, GradeTooLowException, "AForm grade too low")
ERR_WHAT(AForm, GradeTooHighException, "AForm grade too high")
ERR_WHAT(AForm, FormNotSign, "AForm form not sign")

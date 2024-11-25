#pragma once

#include "Bureaucrat.h"
#include "ErrClassTemplate.h"
#include <string>

class AForm {
  public:
    AForm(const std::string &name, int minimumGradeSign,
          int minimumGradeExecute);
    AForm(const AForm &ref);
    AForm(void);
    virtual ~AForm(void);

    ERR_CLASS(GradeTooHighException)
    ERR_CLASS(GradeTooLowException)
    ERR_CLASS(FormNotSign)

    AForm &operator=(AForm const &src);

    const std::string &GetName() const;
    bool               GetIsSigned() const;
    int                GetMinimumGradeSign() const;
    int                GetMinimumGradeExecute() const;

    void beSigned(const Bureaucrat &b);
    void execute(const Bureaucrat &b) const;

  private:
    std::string _name;
    bool        _isSigned;
    const int   _minimumGradeSign;
    const int   _minimumGradeExecute;

    void         _checkGrade() const;
    virtual void _interExecute(const Bureaucrat &b) const = 0;
};

std::ostream &operator<<(std::ostream &o, const AForm &a);

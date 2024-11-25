#pragma once

#include "Bureaucrat.h"
#include "ErrClassTemplate.h"
#include <string>

class Form {
  public:
    Form(const std::string &name, int minimumGradeSign, int minimumGradeExecute);
    Form(const Form &ref);
    Form(void);
    ~Form(void);

    ERR_CLASS(GradeTooHighException)
    ERR_CLASS(GradeTooLowException)

    Form &operator=(Form const &src);

    const std::string &GetName() const;
    bool               GetIsSigned() const;
    int                GetMinimumGradeSign() const;
    int                GetMinimumGradeExecute() const;

	void				beSign(const Bureaucrat &b);

  private:
    std::string _name;
    bool        _isSigned;
    const int   _minimumGradeSign;
    const int   _minimumGradeExecute;

    void _checkGrade() const;
};

std::ostream& operator<<(std::ostream& o, const Form& a);

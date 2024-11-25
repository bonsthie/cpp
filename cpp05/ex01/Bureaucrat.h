#pragma once

#define LOWESTGRADE 150
#define HIGHESTGRADE 1

#include "ErrClassTemplate.h"
#include <string>
#include <iostream>

class Form;

class Bureaucrat {
  public:
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &ref);
    Bureaucrat(void);
    ~Bureaucrat(void);

    ERR_CLASS(GradeTooHighException)
    ERR_CLASS(GradeTooLowException)

    const std::string &getName() const;
    int               getGrade() const;

	void				incrementGrade();
	void				decrementGrade();

	void				signForm(Form &form);

    Bureaucrat &operator=(Bureaucrat const &src);
    Bureaucrat &operator++(void);
    Bureaucrat  operator++(int);
    Bureaucrat &operator--(void);
    Bureaucrat  operator--(int);

  private:
    const std::string _name;
    int               _grade;
};

std::ostream &operator<<(std::ostream &oStream, Bureaucrat &value);

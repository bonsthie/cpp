#include "Bureaucrat.h"
#include <exception>
#include <iostream>

void test_grade(std::string name, int grade) {
    try {
        Bureaucrat test(name, grade);
		std::cout << test << std::endl;
    }
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "grade to low err msg :" << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "grade to high err msg :" << e.what() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int main() {
    try {
        Bureaucrat yes("yes", 1);
        std::cout << "before " << yes << std::endl;
        for (int i = 0; i < 10; i++)
            yes--;
        std::cout << "after " << yes << std::endl;
        for (int i = 0; i < 100; i++)
            yes.incrementGrade();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

	test_grade("has to low", 200);
	test_grade("has to high", 0);
	test_grade("perfect chill guy", 1);
}

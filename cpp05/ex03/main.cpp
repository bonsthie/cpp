#include "AForm.h"
#include "Bureaucrat.h"
#include "Intern.h"

#include <unistd.h>

int main() {
	{
        Intern someRandomIntern;
        AForm *rrf;
        rrf = someRandomIntern.makeForm("presidential pardon", "yes");
        std::cout << *rrf << std::endl;
		if (rrf)
			delete rrf;
    }
    {
        Intern someRandomIntern;
        AForm *rrf;
        rrf = someRandomIntern.makeForm("shrubbery creation", "yes");
        std::cout << *rrf << std::endl;
		if (rrf)
			delete rrf;
    }
    {
        Intern someRandomIntern;
        AForm *rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "yes");
        std::cout << *rrf << std::endl;
		if (rrf)
			delete rrf;
    }
    {
        Intern someRandomIntern;
        AForm *rrf;
        rrf = someRandomIntern.makeForm("fasfsaefasf", "fail");
		if (rrf)
			delete rrf;
    }
}

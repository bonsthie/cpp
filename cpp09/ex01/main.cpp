#include "RPN.h"
#include <iostream>


int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Error" << std::endl;
    }
	if (rpn(av[1]))
		std::cerr << "Error" << std::endl;
	
}

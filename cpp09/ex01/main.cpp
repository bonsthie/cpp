#include "RPN.h"
#include <iostream>


int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Error" << std::endl;
    }
	
	try {
		rpn(av[1]);
	}
	catch (const std::exception &e) {
		std::cerr << "Error : " << e.what() << std::endl; 
	}
}

#include <stdint.h>
#include <iostream>
#include <ostream>
#include <vector>

std::vector<uint32_t> pmergeme(const char *str);

int main(int ac, char **av) {
	if (ac != 2) return 1;

	try {
		pmergeme(av[1]);
	}
	catch (const std::exception &e){
		std::cout << "Error " << e.what() << std::endl; 
		return 1;

	}

}

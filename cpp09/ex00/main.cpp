#include "Date.h"
#include <iostream>
#include <exception>
#include <string>

int main(int ac, char **av) {
	if (ac != 2)
		return (1);
	std::string str(av[1]);
	try {
		Date test(str);

	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

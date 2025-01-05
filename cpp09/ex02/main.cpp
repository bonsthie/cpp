#include <stdint.h>
#include <iostream>
#include <ostream>
#include <vector>

std::vector<uint32_t> pmergeme(const char *str);

int main(int ac, char **av) {
	if (ac != 2) return 1;

	try {
		std::vector<uint32_t> res = pmergeme(av[1]);
		for (size_t i = 0; i < res.size(); i++) {
			std::cout << res[i];
			if (i < res.size() - 1)
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	catch (const std::exception &e){
		std::cout << "Error " << e.what() << std::endl; 
		return 1;

	}

}

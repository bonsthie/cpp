#include <cstdlib>
#include <iostream>
#include <ostream>
#include <stdint.h>

void pmergeme(char **input);


int main(int ac, char **av) {
    if (ac < 2)
        return 1;

    try {
        pmergeme(++av);

    } catch (const std::exception &e) {
        std::cout << "Error " << e.what() << std::endl;
        return 1;
    }
}

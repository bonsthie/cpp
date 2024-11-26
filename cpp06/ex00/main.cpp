#include "ScalarConverter.h"

int main(int ac, char **av) {
  if (ac < 2) {
    std::cout << "require an input" << std::endl;
    return 1;
  }
  ScalarConverter test;

  test.convert(av[1]);
}

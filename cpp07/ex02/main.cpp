#include "Array.hpp"
#include <iostream>

int main() {
	Array<int> str(10);
	str[0] = 1;
	str[1] = 2;
	str[2] = 3;
	str[3] = 4;
	str[4] = 5;
	str[5] = 6;
	str[6] = 7;
	str[7] = 8;
	str[8] = 9;
	str[9] = 10;
	std::cout << str << std::endl;
}

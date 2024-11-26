
#include <cctype>
#include <iostream>
#include <string.h>
#include "iter.hpp"

void toupper_yes(char &c) { c = toupper(c); }
void mult2(int &i) { i *= 2; }

int main() {
	char str[] = "what up !";
	std::cout << str << std::endl;
	iter(str, strlen(str), toupper_yes);
	std::cout << str << std::endl;

	int tab[5] = {1, 2 , 3, 4 , 5};
	for (int i = 0; i < 5; i++)
		std::cout << tab[i] << " ";
	std::cout << std::endl;
	iter(tab, 5, mult2);
	for (int i = 0; i < 5; i++)
		std::cout << tab[i] << " ";
	std::cout << std::endl;
}

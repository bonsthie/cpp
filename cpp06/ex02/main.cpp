#include "Base.h"
#include <iostream>

int main()
{
	Base *yes = generate();
	std::cout << "pointer idendifer : ";
	identify(yes);
	std::cout << "ref idendifer : ";
	identify(*yes);
}

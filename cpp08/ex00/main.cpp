#include "easyfind.h"
#include <iostream>
#include <list>

int main() {
	std::list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);

	(void)l.begin();

	std::cout << "is 7 in the list : " << (easyfind(l, 7) ? "yes" : "no") << std::endl;
	std::cout << "is 1 in the list : " << (easyfind(l, 1) ? "yes" : "no") << std::endl;
}

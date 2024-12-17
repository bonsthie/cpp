#include "Serializer.h"
#include <iostream>

int main()
{
	Data yes;

	yes.foo = 123;
	std::cout << "base : yes (" << &yes << ") foo = " << yes.foo << std::endl;

	uintptr_t no = Serializer::serialize(&yes);
	std::cout << "after erilasize : no (0x" << std::hex << no << std::dec << ")\n";

	Data *new_yes = Serializer::deserialize(no);
	std::cout << "after deserialize : new_yes (" << new_yes << ") foo = " << new_yes->foo << std::endl;


}

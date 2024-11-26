#include "Serializer.h"
#include <iostream>

int main()
{
	Data yes;
	Serializer serializer;

	yes.foo = 123;
	std::cout << "base : yes (" << &yes << ") foo = " << yes.foo << std::endl;

	uintptr_t no = serializer.serialize(&yes);
	std::cout << "after erilasize : no (0x" << std::hex << no << std::dec << ")\n";

	Data *new_yes = serializer.deserialize(no);
	std::cout << "after deserialize : new_yes (" << new_yes << ") foo = " << new_yes->foo << std::endl;


}

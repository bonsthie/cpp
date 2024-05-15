#include "Zombie.h"

int main()
{
	Zombie *heap = newZombie("heap heap");
	heap->announce();
	delete heap;
	randomChump("stack stack");
}

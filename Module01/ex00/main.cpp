#include "Zombie.hpp"

void randomChump( std::string name );

Zombie* newZombie( std::string name );

int main() {
    randomChump("ZombieDUDU_stack");
	Zombie *b = newZombie("ZombieDUDU_heap");
	b->announce();
    delete b;
    return 0;
}
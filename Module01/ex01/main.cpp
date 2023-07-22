#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main() {
    Zombie *list_zombies;
    
    list_zombies = zombieHorde(5, "ZombieDUDU_stack");
	for (int i = 0; i < 5; i++)
        list_zombies[i].announce();
    delete[] list_zombies;
    return 0;
}
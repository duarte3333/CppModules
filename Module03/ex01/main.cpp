#include "ScavTrap.hpp"

int main()
{
    ScavTrap a("curandeira");

    a.attack("magico");
    a.takeDamage(2);
    a.beRepaired(4);

}
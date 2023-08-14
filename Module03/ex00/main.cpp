#include "ClapTrap.hpp"

int main()
{
	ClapTrap A = ClapTrap("Mago");
	ClapTrap B = ClapTrap("Guerreiro");

	std::cout << A.getName() << std::endl;
	std::cout << B.getName() << std::endl;

	A.attack(B.getName());
	B.takeDamage(A.getDamageAttack());
	B.beRepaired(2);
	
	B.attack(A.getName());
	A.beRepaired(2);
}
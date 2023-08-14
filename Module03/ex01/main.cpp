#include "ScavTrap.hpp"

#include "ScavTrap.hpp"


int main(void) {
	ScavTrap A("curandeira");
	ScavTrap B(A);
	ScavTrap C("mago");

	B.guardGate();

	C.attack(B.getName());
	B.takeDamage(C.getDamageAttack());

	B.attack(C.getName());
	C.takeDamage(B.getDamageAttack());

	C.beRepaired(2);
}
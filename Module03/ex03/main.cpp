#include "DiamondTrap.hpp"

int main(void) {
	DiamondTrap B("JOAO PASSARINHO");
	DiamondTrap C("TONI MARIA");

	B.whoAmI();

	C.attack(B.getName());
	B.takeDamage(C.getDamageAttack());

	B.attack(C.getName());
	C.takeDamage(B.getDamageAttack());
	B.guardGate();
}
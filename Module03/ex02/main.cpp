#include "FragTrap.hpp"

int main(void) {
	FragTrap A("curandeira");
	FragTrap B(A);
	FragTrap C("mago");

	B.highFivesGuys();

	C.attack(B.getName());
	B.takeDamage(C.getDamageAttack());

	B.attack(C.getName());
	C.takeDamage(B.getDamageAttack());
}
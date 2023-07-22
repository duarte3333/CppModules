#include "HumanB.hpp"

HumanB::HumanB(std::string name) : myName(name) {
	this->myWeaponB = 0;
}

HumanB::~HumanB() {
	std::cout << this->myName << " died!\n";
}

void HumanB::attack() {
	if (!this->myWeaponB)
        std::cout << this->myName << " attacks with their bare hands\n";
    else
        std::cout << this->myName << " attacks with their " << this->myWeaponB->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weaponB) {
	this->myWeaponB = &weaponB;
}


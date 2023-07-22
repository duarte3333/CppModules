#include "Weapon.hpp"

/* Existem duas possibilidades de constructors.
Se quando criar uma Weapon for dado como argumento
uma string ele escolhe o segundo constructor. */

Weapon::Weapon(void) {
    std::cout << "Weapon created\n";
}

Weapon::Weapon(std::string novoType) {
    setType(novoType);
}

Weapon::~Weapon() {
    std::cout << "Destroyed weapon\n";
}

const std::string &Weapon::getType() {
    std::string &ref = this->myType;
    return (ref);
}

void Weapon::setType(std::string newType) {
    this->myType = newType;
}
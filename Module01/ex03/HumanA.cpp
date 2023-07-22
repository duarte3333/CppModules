#include "HumanA.hpp"

/* Inicializar tudo em lista - melhor perfomance - Inicializa antes de executar o body do construtor */
HumanA::HumanA(std::string name, Weapon &weapon): myWeaponA(weapon), myName(name){
}

/* Outra opcao - pior performance - faz default inicialization e depois
atribui novos valores às variaveis */
// HumanA::HumanA(std::string name, Weapon &weapon) {
//     this->myName = name;
//     this->myWeaponA = weapon;
// }

HumanA::~HumanA() {
    std::cout << this->myName << " died!\n";
}

void HumanA::attack() {
    std::cout << this->myName << " attacks with their " << this->myWeaponA.getType() << std::endl;
}
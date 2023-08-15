#include "Character.hpp"

Character::Character() {
    for (int i = 0; i < 4; i++){
        materias[i] = 0;
    }
    std::cout << "Default character constructor called" << std::endl;
}

Character::Character(std::string nameInput){
    for (int i = 0; i < 4; i++){
        materias[i] = 0;
    }
    name = nameInput;
    std::cout << "Character constructor called" << std::endl;
}

Character::~Character(){
    for (int i = 0; i < 4; i++){
        delete materias[i];
    }
    std::cout << "Character destructor called" << std::endl;
}

Character::Character(const Character &other){
    *this = other;
}

Character& Character::operator=(const Character& other){
    if (this != &other){
        name = other.getName();
        for (int i = 0; i < 4; i++){
            delete materias[i];
            materias[i] = other.materias[i]->clone();
        }
    }
    return (*this);
}

const std::string& Character::getName() const{
    return(name);
}

void Character::equip(AMateria* m){
    std::cout << m->getType() << " equiped!" << std::endl;
    for(int i = 0; i < 4; i++){
        if (!materias[i]){
            materias[i] = m;
            m->equiped = 1;
            break;
        }
    }
}

void Character::unequip(int idx){
    materias[idx]->equiped = 0;
    materias[idx] = 0;
}

void Character::use(int idx, ICharacter& target){
    if (materias[idx])
        materias[idx]->use(target);
}
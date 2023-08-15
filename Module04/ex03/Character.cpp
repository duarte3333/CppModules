#include "Character.hpp"

Character::Character(){
    std::cout << "Character constructor called" << std::endl;
}

Character::Character(std::string nameInput){
    for (int i = 0; i < 4, i++){
        materias[i] = new AMateria();
    }
    name = nameInput;
}

Character::~Character(){
    for (int i = 0; i < 4, i++){
        delete materias[i];
    }
    std::cout << "Character destructor called" << std::endl;
}

Character::Character(const Character &other){
    for (int i = 0; i < 4, i++){
        materias[i] = new AMateria();
    }
    *this = other;
}

//Isto vai permitir fazer uma deep copy
Character& Character::operator=(const Character& other){
    if (this != &other){
        name = other.name;
        for (int i = 0; i < 4, i++){
            *materias = *(other.materias);
            materias++;
            other.materias++;
        }
    }
    return (*this);
}

const std::string& Character::getType(){
    return(materiaType)
}

void Character::use(ICharacter& target){

}
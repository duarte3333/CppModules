#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
    std::cout << "Cure constructor called" << std::endl;
}

Cure::~Cure(){
    std::cout << "Cure destructor called" << std::endl;
}

Cure::Cure(const Cure &other){
    *this = other;
}

//Isto vai permitir fazer uma deep copy
Cure& Cure::operator=(const Cure& other){
    if (this != &other){
        materiaType = other.getType();
    }
    return (*this);
}

void Cure::use(ICharacter& target){

}
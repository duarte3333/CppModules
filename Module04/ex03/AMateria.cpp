#include "AMateria.hpp"

AMateria::AMateria(){
    std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type){
    materiaType = type;
}

AMateria::~AMateria(){
    std::cout << "AMateria destructor called" << std::endl;
}

AMateria::AMateria(const AMateria &other){
    *this = other;
}

//Isto vai permitir fazer uma deep copy
AMateria& AMateria::operator=(const AMateria& other){
    if (this != &other){
        materiaType = other.getType();
    }
    return (*this);
}

const std::string& AMateria::getType(){
    return(materiaType)
}

void AMateria::use(ICharacter& target){

}
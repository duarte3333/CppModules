#include "AMateria.hpp"

AMateria::AMateria() : equiped(0){
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

AMateria& AMateria::operator=(const AMateria& other){
    if (this != &other){
        materiaType = other.getType();
    }
    return (*this);
}

const std::string& AMateria::getType() const{
    return(materiaType);
}

void AMateria::use(ICharacter& target){

        std::cout << "* Abstract Materia *" << target.getName() \
        << " *"<< std::endl;
}
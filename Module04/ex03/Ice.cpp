#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
    std::cout << "Ice constructor called" << std::endl;
}

Ice::~Ice(){
    std::cout << "Ice destructor called" << std::endl;
}

Ice::Ice(const Ice &other){
    *this = other;
}

//Isto vai permitir fazer uma deep copy
Ice& Ice::operator=(const Ice& other){
    if (this != &other){
        materiaType = other.getType();
    }
    return (*this);
}

void Ice::use(ICharacter& target){

}
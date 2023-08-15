#include "AbsAnimal.hpp"

AbsAnimal::AbsAnimal(){
    std::cout << "AbsAnimal constructor called" << std::endl;
}

AbsAnimal::~AbsAnimal(){
    std::cout << "AbsAnimal destructor called" << std::endl;
}

AbsAnimal::AbsAnimal(const AbsAnimal &other){
    *this = other;
}

//Isto vai permitir fazer uma deep copy
AbsAnimal& AbsAnimal::operator=(const AbsAnimal& other){
    if (this != &other){
        type = other.getType();
    }
    return (*this);
}

void AbsAnimal::setType(std::string InputType){
    this->type =  InputType;
}

std::string AbsAnimal::getType(void) const{
    return (this->type);
}

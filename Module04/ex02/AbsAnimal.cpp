#include "AbsAnimal.hpp"
#include "Brain.hpp"

AbsAnimal::AbsAnimal(){
    brain = new Brain();
    std::cout << "AbsAnimal constructor called" << std::endl;
}

AbsAnimal::~AbsAnimal(){
    delete brain;
    std::cout << "AbsAnimal destructor called" << std::endl;
}

AbsAnimal::AbsAnimal(const AbsAnimal &other){
    brain = new Brain();
    *this = other;
}

//Isto vai permitir fazer uma deep copy
AbsAnimal& AbsAnimal::operator=(const AbsAnimal& other){
    if (this != &other)
    {
        type = other.getType();
        *brain = *(other.brain);
    }
    return (*this);
}

void AbsAnimal::setType(std::string InputType){
    this->type =  InputType;
}

std::string AbsAnimal::getType(void) const{
    return (this->type);
}



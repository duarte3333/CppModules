#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(){
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other){
    *this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other){
    if (this != &other)
    {
        type = other.getType();
    }
    return (*this);
}

void WrongAnimal::setType(std::string InputType){
    this->type =  InputType;
}

std::string WrongAnimal::getType(void) const{
    return (this->type);
}

void WrongAnimal::makeSound() const{
    std::cout << "I am a WrongAnimal" << std::endl;
}
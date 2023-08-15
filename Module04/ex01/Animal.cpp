#include "Animal.hpp"
#include "Brain.hpp"

Animal::Animal(){
    std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal(){
    std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal &other){
    *this = other;
}

//Isto vai permitir fazer uma deep copy
Animal& Animal::operator=(const Animal& other){
    if (this != &other){
        type = other.getType();
    }
    return (*this);
}

void Animal::setType(std::string InputType){
    this->type =  InputType;
}

std::string Animal::getType(void) const{
    return (this->type);
}

void Animal::makeSound() const{
    std::cout << "I am a animal" << std::endl;
}

#include "Animal.hpp"
#include "Brain.hpp"

Animal::Animal(){
    brain = new Brain();
    std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal(){
    delete brain;
    std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal &other){
    brain = new Brain();
    *this = other;
}

//Isto vai permitir fazer uma deep copy
Animal& Animal::operator=(const Animal& other){
    if (this != &other)
    {
        type = other.getType();
        *brain = *(other.brain);
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

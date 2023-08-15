#include "Dog.hpp"

Dog::Dog() : Animal(){
    std::cout << "Dog constructor called" << std::endl;
    setType("Dog");
}

Dog::~Dog(){
    std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other){
    *this = other;
}

Dog& Dog::operator=(const Dog& other){
    if (this != &other)
    {
        type = other.getType();
        brain = other.brain;
    }
    return (*this);
}

void Dog::makeSound() const{
    std::cout << "Bark bark!" << std::endl;
}
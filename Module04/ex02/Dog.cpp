#include "Dog.hpp"

Dog::Dog(){
    std::cout << "Dog constructor called" << std::endl;
    brain = new Brain();
    setType("Dog");
}

Dog::~Dog(){
    delete brain;
    std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &other){
    brain = new Brain();
    *this = other;
}

Dog& Dog::operator=(const Dog& other){
    std::cout << "Dog copy constructor called" << std::endl;
    if (this != &other)
    {
        type = other.getType();
        *brain = *(other.brain);
    }
    return (*this);
}

void Dog::makeSound() const{
    std::cout << "Bark bark!" << std::endl;
}

void Dog::setBrainIdea(std::string idea, int index){
    brain->setIdea(idea, index);
}

void Dog::showBrainIdea(int index){
    brain->showIdea(index);
}
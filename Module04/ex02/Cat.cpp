#include "Cat.hpp"

Cat::Cat() {
    std::cout << "Cat constructor called" << std::endl;
    brain = new Brain();
    setType("Cat");
}

Cat::~Cat(){
    delete brain;
    std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &other) {
    brain = new Brain();
    *this = other;
}

Cat& Cat::operator=(const Cat& other){
    if (this != &other)
    {
        type = other.getType();
        *brain = *(other.brain);
    }
    return (*this);
}

void Cat::makeSound() const{
    std::cout << "Miau Miau!" << std::endl;
}

void Cat::setBrainIdea(std::string idea, int index){
    brain->setIdea(idea, index);
}

void Cat::showBrainIdea(int index){
    brain->showIdea(index);
}
#include "Cat.hpp"

Cat::Cat() : AbsAnimal(){
    std::cout << "Cat constructor called" << std::endl;
    setType("Cat");
}

Cat::~Cat(){
    std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &other) : AbsAnimal(other){
    *this = other;
}

Cat& Cat::operator=(const Cat& other){
    if (this != &other)
    {
        type = other.getType();
        brain = other.brain;
    }
    return (*this);
}

void Cat::makeSound() const{
    std::cout << "Miau Miau!" << std::endl;
}
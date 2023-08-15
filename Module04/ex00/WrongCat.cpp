#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal(){
    std::cout << "WrongCat constructor called" << std::endl;
    setType("WrongCat");
}

WrongCat::~WrongCat(){
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other){
    *this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other){
    if (this != &other)
    {
        type = other.getType();
    }
    return (*this);
}

void WrongCat::makeSound() const{
    std::cout << "Wrong Miau Wrong Miau!" << std::endl;
}
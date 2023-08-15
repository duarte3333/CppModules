#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++){
        inventory[i] = 0;
    }
    std::cout << "MateriaSource constructor called" << std::endl;
}

MateriaSource::~MateriaSource(){
    for (int i = 0; i < 4; i++){
        delete inventory[i];
    }
    std::cout << "MateriaSource destructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other){
    *this = other;
}

//Isto vai permitir fazer uma deep copy
MateriaSource& MateriaSource::operator=(const MateriaSource& other){
    if (this != &other){
        for(int i =0; i < 4; i++){
            delete inventory[i];
            inventory[i] = other.inventory[i]->clone();

        }
    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria* newMateria){
    for (int i = 0; i < 4; i++){
        if (!inventory[i]){
            inventory[i] = newMateria;
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type){
    for (int i = 0; i < 4; i++){
        if (inventory[i]->getType() == type){
            return (inventory[i]->clone());
        }
    }
    return (0);
}

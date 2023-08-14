#include "FragTrap.hpp"

FragTrap::FragTrap(){
    std::cout << "FragTrap default constructor called" << std::endl;
    this->attackDamage = 30;
    this->energyPoints = 100;
    this->hitPoints = 100;
}

FragTrap::FragTrap(std::string nameFrag) : ClapTrap(nameFrag) {
    std::cout << "FragTrap Constructor called" << std::endl;
    this->attackDamage = 30;
    this->energyPoints = 100;
    this->hitPoints = 100;
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap Destructor called " << std::endl;
}

FragTrap::FragTrap(const FragTrap &other){
    std::cout << "FragTrap Copy Constructor called" << std::endl;
    *this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other){
    if (this != &other)
    {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    return (*this);
}

void FragTrap::highFivesGuys(){
    std::cout << "FragTrap " << name << " gives a high five :)" << std::endl;
}
#include "FragTrap.hpp"

FragTrap::FragTrap(){
    std::cout << "FragTrap default constructor called" << std::endl;
    this->attackDamage = 30;
    this->energyPoints = 100;
    this->hitPoints = 100;
}

FragTrap::FragTrap(std::string nameFrag) : ClapTrap(nameFrag) {
    this->attackDamage = 30;
    this->energyPoints = 100;
    this->hitPoints = 100;
    std::cout << "----------------------------" << std::endl;
    std::cout << "FragTrap Constructor called" << std::endl;
    std::cout << "Attack damage " << attackDamage << std::endl;
    std::cout << "Starting hit points " << hitPoints << std::endl;
    std::cout << "Starting energy points " << energyPoints << std::endl;
    std::cout << "----------------------------" << std::endl;

}

FragTrap::~FragTrap(){
    std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other){
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
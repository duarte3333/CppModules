#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string nameInput) : name(nameInput), hitPoints(10),
energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap Constructor called" << std::endl;
}

ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other){
    *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other){
    if (this != &other)
    {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
    }
    return (*this);
}

void ClapTrap::attack(const std::string& target){
    std::cout << "ClapTrap " << name << " attacks " << target << \
     ", causing " << attackDamage << " points of damage" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
    if (energyPoints && hitPoints){
        hitPoints -= amount;
        energyPoints--;
    }
    std::cout << "ClapTrap " << name << " take damage" << \
     ", ans now has " << hitPoints << " hitpoints of health." << std::endl;
    std::cout << "Now he has "<< energyPoints << " energy points" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
    if (energyPoints && hitPoints){
        hitPoints += amount;
        energyPoints--;
    }
    std::cout << "ClapTrap " << name << " was repaired" << \
     ", and now has " << hitPoints << " hitpoints of health." << std::endl;
    std::cout << "Now he has "<< energyPoints << " energy points" << std::endl;
}


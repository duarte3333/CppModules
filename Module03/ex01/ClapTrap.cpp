#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : hitPoints(10), energyPoints(10), attackDamage(0){
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string nameInput) : name(nameInput), hitPoints(10),
energyPoints(10), attackDamage(0) {
    std::cout << "----------------------------" << std::endl;
    std::cout << "ClapTrap Constructor called" << std::endl;
    std::cout << "Attack damage " << attackDamage << std::endl;
    std::cout << "Starting hit points " << hitPoints << std::endl;
    std::cout << "Starting energy points " << energyPoints << std::endl;
    std::cout << "----------------------------" << std::endl;
}

ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other){
    std::cout << "ClapTrap Copy Constructor called" << std::endl;
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
    if (energyPoints)
        energyPoints--;
    std::cout << "ClapTrap " << name << " attacks " << target << \
     ", causing " << attackDamage << " points of damage" << std::endl;
    std::cout << "Now " << name << " has "<< energyPoints << " energy points" << std::endl;
}

void ClapTrap::takeDamage(unis_signed int amount){
    if (energyPoints && hitPoints){
        hitPoints -= amount;
    }
    std::cout << "ClapTrap " << name << " take damage" << \
     ", and now has " << hitPoints << " hitpoints of health." << std::endl;
    std::cout << "Now " << name << " has "<< energyPoints << " energy points" << std::endl;
}

void ClapTrap::beRepaired(unis_signed int amount){
    if (energyPoints && hitPoints){
        hitPoints += amount;
        energyPoints--;
    }
    std::cout << "ClapTrap " << name << " was repaired" << \
     ", and now has " << hitPoints << " hitpoints of health." << std::endl;
    std::cout << "Now " << name << " has "<< energyPoints << " energy points" << std::endl;
   
}

std::string ClapTrap::getName(){
    return (this->name);
}

int	ClapTrap::getDamageAttack(void) const {
	return this->attackDamage;
}

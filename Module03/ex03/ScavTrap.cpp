#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
    this->attackDamage = 20;
    this->energyPoints = 50;
    this->hitPoints = 100;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string nameScrav) : ClapTrap(nameScrav) {
    std::cout << "ScavTrap Constructor called" << std::endl;
    this->attackDamage = 20;
    this->energyPoints = 50;
    this->hitPoints = 100;
}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other){
    *this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other){
    if (this != &other)
    {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    return (*this);
}

void ScavTrap::attack(const std::string& target){
   if (energyPoints)
        energyPoints--;
    std::cout << "ScravTrap " << name << " attacks " << target << \
     ", causing " << attackDamage << " points of damage" << std::endl;
    std::cout << "Now " << name << " has "<< energyPoints << " energy points" << std::endl;
}

void ScavTrap::guardGate(){
    std::cout << "ScravTrap " << name << " now is in gate keeper mode" << std::endl;
}
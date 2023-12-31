#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
    this->attackDamage = 20;
    this->energyPoints = 50;
    this->hitPoints = 100;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string nameScrav) : ClapTrap(nameScrav) {
    this->attackDamage = 20;
    this->energyPoints = 50;
    this->hitPoints = 100;
    std::cout << "----------------------------" << std::endl;
    std::cout << "ScavTrap Constructor called" << std::endl;
    std::cout << "Attack damage " << attackDamage << std::endl;
    std::cout << "Starting hit points " << hitPoints << std::endl;
    std::cout << "Starting energy points " << energyPoints << std::endl;
    std::cout << "----------------------------" << std::endl;

}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other){
    std::cout << "ScravTrap Copy Constructor called" << std::endl;
    *this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other){
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
    std::cout << "ClapTrap " << name << " attacks " << target << \
     ", causing " << attackDamage << " points of damage" << std::endl;
    std::cout << "Now " << name << " has "<< energyPoints << " energy points" << std::endl;
}


void ScavTrap::guardGate(){
    std::cout << "ScravTrap " << name << " now is in gate keeper mode" << std::endl;
}
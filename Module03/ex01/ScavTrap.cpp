#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string nameScrav) : ClapTrap(nameScrav) {
    std::cout << "ClapTrap Constructor called" << std::endl;
    this->attackDamage = 20;
    this->energyPoints = 50;
    this->hitPoints = 100;
}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap Destructor called" << std::endl;
}

void ScavTrap::guardGate(){
    std::cout << "ScravTrap " << name << " now is in gate keeper mode" << std::endl;
}
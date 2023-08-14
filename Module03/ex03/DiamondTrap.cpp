#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap(){
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string nameD) : ClapTrap(nameD + "_clap_name") ,
FragTrap() , ScavTrap(), name(nameD){
    std::cout << "DiamondTrap Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other){
    *this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other){
    if (this != &other)
    {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    return (*this);
}

DiamondTrap::~DiamondTrap(){
    std::cout << "Diamond Destructor called" << std::endl;
}

void DiamondTrap::whoAmI() {
	std::cout << name << " this is the Diamond's name." << std::endl
	<< ClapTrap::getName() << " this is the ClapTrap's name." << std::endl;
}

// void DiamondTrap::attack(const std::string& target){
//     ScavTrap::attack(target);
// }

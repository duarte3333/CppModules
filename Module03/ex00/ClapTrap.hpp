#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include "string"
#include <iostream>

class ClapTrap {
    private:
        std::string name;
        int hitPoints;
        int energyPoints;
        int attackDamage;
    public:
        ClapTrap();  //Default constructor
        ClapTrap(std::string name); //Constructor
        ~ClapTrap(); //Destructor
        ClapTrap(const ClapTrap &other); //Copy constructor
        //Nao entendo bem a posicao do &
        ClapTrap& operator=(const ClapTrap &other); //Copy assignment operator
        void attack(const std::string& target);
        void takeDamage(unis_signed int amount);
        void beRepaired(unis_signed int amount);
        int	 getDamageAttack(void) const;
        std::string getName();
};

#endif

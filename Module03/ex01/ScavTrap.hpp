#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
    public:
        ScavTrap();
        ScavTrap(std::string nameScrav);
        ~ScavTrap();
        void attack(std::string target); 
        void guardGate();
};

#endif
#pragma once
#ifndef HUMANB_HPP
#define HUMANB_HPP
#include "Weapon.hpp"
#include  <iostream>

/* Usar um pointer na para myWeaponB permite
ter um estado de associação nula, o estado em que
não existe armadura */
class HumanB {
	private:
		Weapon 		*myWeaponB;
		std::string myName;

	public:
	    HumanB(std::string name);
    	~HumanB();
		void attack();
		void setWeapon(Weapon &weapon);
};

#endif
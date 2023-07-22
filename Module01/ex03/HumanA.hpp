#pragma once
#ifndef HUMANA_HPP
#define HUMANA_HPP
#include "Weapon.hpp"

/* Usar uma referencia para myWeaponA implica que
que exista sempre um valor associado a essa variavel.
Alem disso simplifica o gerenciamento de memoria pois nao 
e necessario preocupar com a desalocacao de memoria.*/
class HumanA {
	private:
		Weapon 		&myWeaponA;
		std::string myName;

	public:
	    HumanA(std::string name, Weapon &weapon);
    	~HumanA();
		void attack();
	
};

#endif
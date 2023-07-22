#pragma once
#ifndef WEAPON_HPP
#define WEAPON_HPP
#include  "iostream"

/* Esta classe tem duas possibilidades de constructor */
class Weapon {

	private:
		std::string myType;
	public:
		Weapon();
   		Weapon(std::string type);
    	~Weapon(void);

		const std::string &getType();
		void setType(std::string);
};

#endif
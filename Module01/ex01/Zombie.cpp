#include "Zombie.hpp"

Zombie::Zombie() {
	std::cout << "Zombie was created\n";
}

Zombie::~Zombie() {
	std::cout << this->name << " was destroyed" << std::endl;
}

void Zombie::announce() {
	std::cout << this->name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
	this->name = name;
}
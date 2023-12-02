#include "Zombie.h"
#include <iostream>

Zombie::Zombie() {}

Zombie::Zombie(const std::string &name) : name(name) {}

Zombie::~Zombie() {
	std::cerr << this->name << " is dead" << std::endl;
}

void Zombie::announce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

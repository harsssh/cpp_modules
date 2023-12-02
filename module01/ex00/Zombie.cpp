#include "Zombie.h"
#include <iostream>

Zombie::Zombie(const std::string &name) : name(name) {
	std::cerr << this->name << " is born" << std::endl;
}

Zombie::~Zombie() {
	std::cerr << this->name << " is dead" << std::endl;
}

void Zombie::announce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

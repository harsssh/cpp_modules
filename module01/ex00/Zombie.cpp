#include "Zombie.h"
#include <iostream>

Zombie::Zombie() {}

Zombie::Zombie(const std::string &name) : name(name) {}

Zombie::Zombie(const Zombie &z): name(z.name){}

Zombie::~Zombie() {
	std::cout << this->name << " is dead" << std::endl;
}

Zombie &Zombie::operator=(const Zombie &z) {
	this->name = z.name;
	return *this;
}

void Zombie::announce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

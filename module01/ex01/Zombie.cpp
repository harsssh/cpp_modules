#include "Zombie.h"
#include <iostream>

Zombie::Zombie() {}

Zombie::Zombie(const std::string &name) : name_(name) {}

Zombie::~Zombie() {
	std::cerr << name_ << " is dead" << std::endl;
}

void Zombie::announce() {
	std::cout << name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string &name) {
	name_ = name;
}

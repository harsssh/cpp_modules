#include "Zombie.h"
#include <iostream>

Zombie::Zombie() {
	std::cerr << "Zombie is born" << std::endl;
}

Zombie::Zombie(const std::string &name) : name(name) {
	std::cerr << this->name << " is born" << std::endl;
}

Zombie::Zombie(const Zombie &z): name(z.name){
	std::cerr << this->name << " is born by copy" << std::endl;
}

Zombie::~Zombie() {
	std::cerr << this->name << " is dead" << std::endl;
}

Zombie &Zombie::operator=(const Zombie &z) {
	this->name = z.name;
	return *this;
}

void Zombie::announce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

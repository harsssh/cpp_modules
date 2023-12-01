#include "Zombie.h"

Zombie *newZombie(std::string name) {
	Zombie *z = new Zombie(name);
	return z;
}

void randomChump(std::string name) {
	Zombie z(name);
	z.announce();
}

int main() {
	Zombie *z = newZombie("Alice");
	z->announce();
	delete z;

	randomChump("Bob");
}

#include "Zombie.h"

int main() {
	Zombie *z = newZombie("Alice");
	z->announce();
	delete z;

	randomChump("Bob");
}

#include "Zombie.h"
#include <iostream>

int main() {
	const int n = 5;
	Zombie *z = zombieHorde(n, "Alice");
	for (int i = 0; i < n; i++) {
		std::cout << i << "-th zombie:" << std::endl;
		z[i].announce();
	}
	delete[] z;
}

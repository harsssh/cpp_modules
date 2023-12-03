#include <iostream>
#include <climits>
#include "ClapTrap.h"

int main() {
	ClapTrap player("player");

	std::cout << "[simple attack]" << std::endl;
	player.attack("enemy");

	std::cout << std::endl;

	std::cout << "[simple take damage]" << std::endl;
	player.takeDamage(5);

	std::cout << std::endl;

	std::cout << "[simple repair]" << std::endl;
	player.beRepaired(5);

	std::cout << std::endl;

	std::cout << "[repair UINT_MAX / 2 three times]" << std::endl;
	player.beRepaired(UINT_MAX / 2);
	player.beRepaired(UINT_MAX / 2);
	player.beRepaired(UINT_MAX / 2);	// cannot be repaired

	std::cout << std::endl;

	std::cout << "[attack without energy]" << std::endl;
	int remainingEnergy = 6;
	while (remainingEnergy--) {
		player.attack("enemy");
	}
	player.attack("enemy");

	std::cout << std::endl;

	std::cout << "[repair without energy]" << std::endl;
	player.beRepaired(1);

	std::cout << std::endl;

	std::cout << "[take damage and death]" << std::endl;
	player.takeDamage(UINT_MAX);

	std::cout << std::endl;

	std::cout << "[take damage after death]" << std::endl;
	player.takeDamage(1);

	std::cout << std::endl;

	std::cout << "[attack after death]" << std::endl;
	player.attack("enemy");

	std::cout << std::endl;

	std::cout << "[repair after death]" << std::endl;
	player.beRepaired(1);
}

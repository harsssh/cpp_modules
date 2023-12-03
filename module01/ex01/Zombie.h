#ifndef CPP_MODULES_ZOMBIE_H
#define CPP_MODULES_ZOMBIE_H

#include <string>

class Zombie {
private:
	std::string name;

public:
	Zombie();

	Zombie(const std::string &name);

	~Zombie();

	void announce();
};

Zombie *zombieHorde(int, std::string);

#endif //CPP_MODULES_ZOMBIE_H

#ifndef CPP_MODULES_ZOMBIE_H
#define CPP_MODULES_ZOMBIE_H

#include <string>

class Zombie {
private:
	std::string name;

public:
	Zombie();

	Zombie(const std::string &name);

	Zombie(const Zombie &z);

	~Zombie();

	Zombie &operator=(const Zombie &z);

	void announce();
};

Zombie *newZombie(std::string);
void randomChump(std::string);

#endif //CPP_MODULES_ZOMBIE_H

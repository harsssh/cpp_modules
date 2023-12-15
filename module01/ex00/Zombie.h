#ifndef CPP_MODULES_ZOMBIE_H
#define CPP_MODULES_ZOMBIE_H

#include <string>

class Zombie {
private:
	std::string name_;

public:
	Zombie(const std::string &name);

	~Zombie();

	void announce();
};

Zombie *newZombie(std::string);

void randomChump(std::string);

#endif //CPP_MODULES_ZOMBIE_H

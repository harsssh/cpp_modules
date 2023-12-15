#ifndef CPP_MODULES_ZOMBIE_H
#define CPP_MODULES_ZOMBIE_H

#include <string>

class Zombie {
private:
	std::string name_;

public:
	Zombie();

	Zombie(const std::string &name);

	~Zombie();

	void announce();

	void setName(std::string name);
};

Zombie *zombieHorde(int, std::string);

#endif //CPP_MODULES_ZOMBIE_H

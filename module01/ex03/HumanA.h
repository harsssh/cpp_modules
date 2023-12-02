#ifndef CPP_MODULES_HUMANA_H
#define CPP_MODULES_HUMANA_H

#include <string>
#include "Weapon.h"

class HumanA {
private:
	std::string name;
	Weapon &weapon;

public:
	HumanA(const std::string &name, Weapon &weapon);

	void attack();
};


#endif //CPP_MODULES_HUMANA_H

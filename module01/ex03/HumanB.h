#ifndef CPP_MODULES_HUMANB_H
#define CPP_MODULES_HUMANB_H

#include <string>
#include "Weapon.h"

class HumanB {
private:
	std::string name_;
	Weapon *weapon_;

public:
	HumanB(const std::string &name);

	void attack();

	void setWeapon(Weapon &w);
};


#endif //CPP_MODULES_HUMANB_H

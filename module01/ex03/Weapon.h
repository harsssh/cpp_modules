#ifndef CPP_MODULES_WEAPON_H
#define CPP_MODULES_WEAPON_H

#include <string>

class Weapon {
private:
	std::string type_;

public:
	Weapon(const std::string &type);

	const std::string &getType() const;

	void setType(const std::string &type);
};


#endif //CPP_MODULES_WEAPON_H

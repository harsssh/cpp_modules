#include "Weapon.h"

Weapon::Weapon(const std::string &type) : type_(type) {}

const std::string &Weapon::getType() const {
	return this->type_;
}

void Weapon::setType(const std::string &type) {
	this->type_ = type;
}

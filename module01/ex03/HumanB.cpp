#include "HumanB.h"
#include <iostream>

HumanB::HumanB(const std::string &name) : name_(name), weapon_(NULL) {}

void HumanB::attack() {
	if (this->weapon_ == NULL)
		std::cout << name_ << " does not have a weapon" << std::endl;
	else
		std::cout << name_ << " attacks with their " << weapon_->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &w) {
	this->weapon_ = &w;
}

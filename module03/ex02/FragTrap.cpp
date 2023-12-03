#include "FragTrap.h"
#include <iostream>

FragTrap::FragTrap() : ClapTrap() {
	std::cerr << "FragTrap default constructor called" << std::endl;
	this->hitPoints_ = 100;
	this->energyPoints_ = 100;
	this->attackDamage_ = 30;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	std::cerr << "FragTrap constructor called" << std::endl;
	this->hitPoints_ = 100;
	this->energyPoints_ = 100;
	this->attackDamage_ = 30;
}

FragTrap::FragTrap(const FragTrap &other) {
	std::cerr << "FragTrap copy constructor called" << std::endl;
	*this = other;
}

FragTrap::~FragTrap() {
	std::cerr << "FragTrap destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	std::cerr << "FragTrap assignation operator called" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

void FragTrap::highFivesGuys() {
	if (!this->isAlive()) {
		this->displayAlreadyDead();
		return;
	}
	if (!this->hasEnoughEnergy()) {
		this->displayNotEnoughEnergy();
		return;
	}

	this->energyPoints_ -= ClapTrap::ACTION_ENERGY_COST;
	std::cout << "FragTrap " << this->name_ << " high fives guys!" << std::endl;
	this->displayStatus();
}

void FragTrap::displayStatus() const {
	std::cout << "FragTrap " << this->name_
			  << " has " << this->hitPoints_ << " hit points and "
			  << this->energyPoints_ << " energy points" << std::endl;
}

void FragTrap::displayAlreadyDead() const {
	std::cout << "FragTrap " << this->name_ << " is already dead!" << std::endl;
}

void FragTrap::displayDead() const {
	std::cout << "FragTrap " << this->name_ << " is dead!" << std::endl;
}

void FragTrap::displayNotEnoughEnergy() const {
	std::cout << "FragTrap " << this->name_ << " has not enough energy!" << std::endl;
}

void FragTrap::displayMaxHitPoints() const {
	std::cout << "FragTrap " << this->name_ << " has max hit points!" << std::endl;
}

void FragTrap::displayBeRepaired(unsigned int amount) const {
	std::cout << "FragTrap " << this->name_
			  << " is repaired for " << amount << " points!" << std::endl;
}

void FragTrap::displayTakeDamage(unsigned int amount) const {
	std::cout << "FragTrap " << this->name_
			  << " takes " << amount << " points of damage!" << std::endl;
}

void FragTrap::displayAttack(const std::string &target) const {
	std::cout << "FragTrap " << this->name_ << " attacks " << target
			  << ", causing " << this->attackDamage_ << " points of damage!" << std::endl;
}

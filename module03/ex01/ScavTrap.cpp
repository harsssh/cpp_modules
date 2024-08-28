#include "ScavTrap.h"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap() {
	std::cerr << "ScavTrap default constructor called" << std::endl;
	this->hitPoints_ = 100;
	this->energyPoints_ = 50;
	this->attackDamage_ = 20;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
	std::cerr << "ScavTrap constructor called" << std::endl;
	this->hitPoints_ = 100;
	this->energyPoints_ = 50;
	this->attackDamage_ = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	std::cerr << "ScavTrap copy constructor called" << std::endl;
	*this = other;
}

ScavTrap::~ScavTrap() {
	std::cerr << "ScavTrap destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	std::cerr << "ScavTrap assignation operator called" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

void ScavTrap::displayStatus() const {
	std::cout << "ScavTrap " << this->name_
			  << " has " << this->hitPoints_ << " hit points and "
			  << this->energyPoints_ << " energy points" << std::endl;
}

void ScavTrap::displayAlreadyDead() const {
	std::cout << "ScavTrap " << this->name_ << " is already dead!" << std::endl;
}

void ScavTrap::displayNotEnoughEnergy() const {
	std::cout << "ScavTrap " << this->name_ << " has not enough energy!" << std::endl;
}

void ScavTrap::displayMaxHitPoints() const {
	std::cout << "ScavTrap " << this->name_ << " has max hit points!" << std::endl;
}

void ScavTrap::displayAttack(const std::string &target) const {
	std::cout << "ScavTrap " << this->name_ << " attacks " << target
			  << ", causing " << this->attackDamage_ << " points of damage!" << std::endl;
}

void ScavTrap::displayDead() const {
	std::cout << "ScavTrap " << this->name_ << " is dead!" << std::endl;
}

void ScavTrap::guardGate() {
	if (!this->isAlive()) {
		this->displayAlreadyDead();
		return;
	}
	if (!this->hasEnoughEnergy()) {
		this->displayNotEnoughEnergy();
		return;
	}

	this->energyPoints_ -= ClapTrap::actionEnergyCost;
	std::cout << "ScavTrap " << this->name_
			  << " is now in Gate keeper mode" << std::endl;
	this->displayStatus();
}

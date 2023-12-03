#ifndef CPP_MODULES_SCAVTRAP_H
#define CPP_MODULES_SCAVTRAP_H

#include "ClapTrap.h"

class ScavTrap: public ClapTrap {
protected:
	// override
	virtual void displayStatus() const;
	virtual void displayAlreadyDead() const;
	virtual void displayDead() const;
	virtual void displayNotEnoughEnergy() const;
	virtual void displayMaxHitPoints() const;
	virtual void displayBeRepaired(unsigned int amount) const;
	virtual void displayTakeDamage(unsigned int amount) const;
	virtual void displayAttack(std::string const &target) const;

public:
	ScavTrap();
	ScavTrap(const std::string &name);
	ScavTrap(const ScavTrap &other);
	~ScavTrap();
	ScavTrap &operator=(const ScavTrap &other);

	void guardGate();
};

#endif //CPP_MODULES_SCAVTRAP_H

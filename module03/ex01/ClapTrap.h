#ifndef CPP_MODULES_CLAPTRAP_H
#define CPP_MODULES_CLAPTRAP_H

#include <string>

class ClapTrap {
private:
	static const unsigned int ACTION_ENERGY_COST = 1;
	static const unsigned int MAX_HIT_POINTS;
	std::string name_;
	unsigned int hitPoints_;
	unsigned int energyPoints_;
	unsigned int attackDamage_;

	bool isAlive() const;
	bool hasEnoughEnergy() const;

	unsigned int getRepairAmount(unsigned int amount) const;

	void displayStatus() const;
	void displayAlreadyDead() const;
	void displayDead() const;
	void displayNotEnoughEnergy() const;
	void displayMaxHitPoints() const;
	void displayBeRepaired(unsigned int amount) const;
	void displayTakeDamage(unsigned int amount) const;
	void displayAttack(std::string const &target) const;

public:
	ClapTrap();

	ClapTrap(const std::string& name);

	ClapTrap(const ClapTrap &clapTrap);

	~ClapTrap();

	ClapTrap &operator=(const ClapTrap &clapTrap);

	void attack(std::string const &target);

	void takeDamage(unsigned int amount);

	void beRepaired(unsigned int amount);
};

#endif //CPP_MODULES_CLAPTRAP_H

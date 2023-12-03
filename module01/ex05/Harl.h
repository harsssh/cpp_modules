#ifndef CPP_MODULES_HARL_H
#define CPP_MODULES_HARL_H

#include <string>

class Harl {
private:
	static const int levels = 4;

	void debug();

	void info();

	void warning();

	void error();

public:
	void complain(std::string level);
};

#endif //CPP_MODULES_HARL_H

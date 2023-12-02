#include "Harl.h"
#include <iostream>

void Harl::debug() {
	std::cout << "[DEBUG] This is debug message" << std::endl;
}

void Harl::info() {
	std::cout << "[INFO] This is info message" << std::endl;
}

void Harl::warning() {
	std::cout << "[WARNING] This is warning message" << std::endl;
}

void Harl::error() {
	std::cout << "[ERROR] This is error message" << std::endl;
}

void Harl::complain(std::string level) {
	void (Harl::*func[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++) {
		if (levels[i] == level) {
			(this->*func[i])();
			return;
		}
	}
	std::cout << "invalid level" << std::endl;
}

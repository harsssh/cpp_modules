#include "Data.h"
#include <iostream>

Data::Data() : str("default") {}

Data::Data(const std::string &s) : str(s) {}

Data::Data(const Data &other) : str(other.str) {}

Data &Data::operator=(const Data &other) {
	if (this != &other)
		str = other.str;
	return *this;
}

Data::~Data() {}

std::ostream &operator<<(std::ostream &os, const Data &data) {
	os << data.str;
	return os;
}

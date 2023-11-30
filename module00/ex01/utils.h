#ifndef CPP_MODULES_UTILS_H
#define CPP_MODULES_UTILS_H

#include <sstream>

template<typename T>
std::string to_string(const T &value) {
	std::ostringstream oss;
	oss << value;
	return oss.str();
}

#endif //CPP_MODULES_UTILS_H

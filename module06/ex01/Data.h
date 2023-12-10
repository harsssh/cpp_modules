#ifndef CPP_MODULES_DATA_H
#define CPP_MODULES_DATA_H

#include <string>

class Data {
public:
	std::string str;

	Data();

	Data(const std::string &s);

	Data(const Data &other);

	Data &operator=(const Data &other);

	~Data();
};

std::ostream &operator<<(std::ostream &os, const Data &data);

#endif //CPP_MODULES_DATA_H

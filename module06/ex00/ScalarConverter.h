#ifndef CPP_MODULES_SCALARCONVERTER_H
#define CPP_MODULES_SCALARCONVERTER_H

#include <string>
#include "Option.h"


class ScalarConverter {
public:
	typedef struct {
		Option<char> *charPtr;
		Option<int> *intPtr;
		Option<float> *floatPtr;
		Option<double> *doublePtr;
	} ConvertResult;

	static ConvertResult convert(const std::string &str);

private:
	static Option<char> *convertToChar(const std::string &str);

	static Option<int> *convertToInt(const std::string &str);

	static Option<float> *convertToFloat(const std::string &str);

	static Option<double> *convertToDouble(const std::string &str);
};

#endif //CPP_MODULES_SCALARCONVERTER_H

#include "ScalarConverter.h"
#include "Some.h"
#include "None.h"
#include <stdexcept>
#include <string>

ScalarConverter::ConvertResult ScalarConverter::convert(const std::string &str) {
	ConvertResult result;
	result.charPtr = convertToChar(str);
	result.intPtr = convertToInt(str);
	result.floatPtr = convertToFloat(str);
	result.doublePtr = convertToDouble(str);
	return result;
}

Option<char> *ScalarConverter::convertToChar(const std::string &str) {
	Option<int> *intPtr = convertToInt(str);
	if (!intPtr->isSome())
		return new None<char>();
	int value = intPtr->unwrap();
	return new Some<char>(static_cast<char>(value));
}

Option<int> *ScalarConverter::convertToInt(const std::string &str) {
	try {
		int value = std::stoi(str);
		return new Some<int>(value);
	} catch (std::exception &e) {
		return new None<int>();
	}
}

Option<float> *ScalarConverter::convertToFloat(const std::string &str) {
	try {
		float value = std::stof(str);
		return new Some<float>(value);
	} catch (std::exception &e) {
		return new None<float>();
	}
}

Option<double> *ScalarConverter::convertToDouble(const std::string &str) {
	try {
		double value = std::stod(str);
		return new Some<double>(value);
	} catch (std::exception &e) {
		return new None<double>();
	}
}

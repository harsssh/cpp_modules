#include "BitcoinExchange.hpp"
#include <sstream>
#include <fstream>
#include <iostream>

BitcoinExchange::BitcoinExchange() : inputFilePath_("input.txt"), dataFilePath_("data.csv"), isValidData_(true) {
	initExchangeRates();
}

BitcoinExchange::BitcoinExchange(const std::string &inputFilePath)
		: inputFilePath_(inputFilePath), dataFilePath_("data.csv"), isValidData_(true) {
	initExchangeRates();
}

BitcoinExchange::BitcoinExchange(const std::string &inputFilePath, const std::string &dataFilePath)
		: inputFilePath_(inputFilePath), dataFilePath_(dataFilePath), isValidData_(true) {
	initExchangeRates();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
		: inputFilePath_(other.inputFilePath_), dataFilePath_(other.dataFilePath_),
		  isValidData_(other.isValidData_), exchangeRates_(other.exchangeRates_) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	if (this != &other) {
		inputFilePath_ = other.inputFilePath_;
		dataFilePath_ = other.dataFilePath_;
		exchangeRates_ = other.exchangeRates_;
		isValidData_ = other.isValidData_;
	}
	return *this;
}

const std::string &BitcoinExchange::getInputFilePath() const {
	return inputFilePath_;
}

const std::string &BitcoinExchange::getDataFilePath() const {
	return dataFilePath_;
}

void BitcoinExchange::run() {
	if (!isValidData_) {
		std::cerr << "database is corrupted" << std::endl;
		return;
	}

	std::ifstream file(inputFilePath_.c_str());
	if (!file.is_open()) {
		std::cerr << "failed to open file: " << inputFilePath_ << std::endl;
		return;
	}

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line)) {
		if (line.empty())
			continue;
		try {
			std::pair<std::string, float> p = parseInputLine(line);
			std::string date = p.first;
			float value = p.second;

			if (value < 0) {
				std::cerr << "Error: not a positive number" << std::endl;
				continue;
			}
			if (value > 1000) {
				std::cerr << "Error: too large a number" << std::endl;
				continue;
			}

			float rate;
			if (exchangeRates_.find(date) != exchangeRates_.end()) {
				// if exists
				rate = exchangeRates_.at(date);
			} else {
				// if not exists
				std::map<std::string, float>::iterator it = exchangeRates_.lower_bound(date);
				if (it == exchangeRates_.end()) {
					std::cerr << "Error: there is no data";
					continue;
				}
				rate = it->second;
			}
			std::cout << date << " => " << value << " = " << rate * value << std::endl;
		} catch (std::exception &e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
}

void BitcoinExchange::initExchangeRates() {
	std::ifstream file(dataFilePath_.c_str());
	if (!file.is_open()) {
		isValidData_ = false;
		std::cerr << "failed to open file: " << inputFilePath_ << std::endl;
		return;
	}

	// skip first line
	std::string line;
	std::getline(file, line);

	while (std::getline(file, line)) {
		if (line.empty())
			continue;
		try {
			std::pair<std::string, float> exchangeRate = parseExchangeRateLine(line);
			exchangeRates_.insert(exchangeRate);
		} catch (std::exception &e) {
			std::cerr << "parse error: " << e.what() << std::endl;
			isValidData_ = false;
			return;
		}
	}
}

std::pair<std::string, float>
BitcoinExchange::parseExchangeRateLine(const std::string &line) throw(std::runtime_error) {
	std::pair<std::string, std::string> linePair = splitLinePair(line, ',');
	std::string dateStr = linePair.first;
	std::string rateStr = linePair.second;

	if (rateStr.find(',') != std::string::npos)
		throw std::runtime_error("invalid exchange rate line: " + line);
	if (!isValidDateStr(dateStr))
		throw std::runtime_error("invalid date string: " + dateStr);

	float rate;
	try {
		rate = s2f(rateStr);
	} catch (std::invalid_argument &e) {
		throw std::runtime_error("invalid exchange rate: " + rateStr);
	}

	return std::pair<std::string, float>(dateStr, rate);
}

std::pair<std::string, float> BitcoinExchange::parseInputLine(const std::string &line) throw(std::runtime_error) {
	std::pair<std::string, std::string> linePair = splitLinePair(line, '|');
	std::string dateStr = trim(linePair.first);
	std::string amountStr = trim(linePair.second);

	if (!isValidDateStr(dateStr))
		throw std::runtime_error("invalid date string: " + dateStr);

	float amount;
	try {
		amount = s2f(amountStr);
	} catch (std::invalid_argument &e) {
		throw std::runtime_error("invalid amount: " + amountStr);
	}

	return std::pair<std::string, float>(dateStr, amount);
}

bool BitcoinExchange::isValidDateStr(const std::string &dateStr) {
	// Year-Month-Day
	if (dateStr.length() != 10)
		return false;
	if (dateStr[4] != '-' || dateStr[7] != '-')
		return false;

	std::string yearStr = dateStr.substr(0, 4);
	std::string monthStr = dateStr.substr(5, 2);
	std::string dayStr = dateStr.substr(8);

	int year, month, day;
	try {
		year = s2i(yearStr);
		month = s2i(monthStr);
		day = s2i(dayStr);
	} catch (std::exception &e) {
		return false;
	}

	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > 31)
		return false;
	if (month == 2) {
		if (isLeapYear(year)) {
			if (day > 29)
				return false;
		} else {
			if (day > 28)
				return false;
		}
	} else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
		return false;
	}
	return true;
}

// string to int
int BitcoinExchange::s2i(const std::string &str) throw(std::invalid_argument) {
	std::istringstream iss(str);
	int i;
	iss >> i;
	if (iss.fail())
		throw std::invalid_argument("invalid string to int conversion: " + str);
	iss.get();    // should read nothing
	if (!iss.eof())
		throw std::invalid_argument("invalid string to int conversion: " + str);
	return i;
}

// string to float
float BitcoinExchange::s2f(const std::string &str) throw(std::invalid_argument) {
	std::istringstream iss(str);
	float f;
	iss >> f;
	if (iss.fail())
		throw std::invalid_argument("invalid string to float conversion: " + str);
	iss.get();    // should read nothing
	if (!iss.eof())
		throw std::invalid_argument("invalid string to float conversion: " + str);
	return f;
}

std::pair<std::string, std::string>
BitcoinExchange::splitLinePair(const std::string &line, char delimiter) throw(std::runtime_error) {
	std::string::size_type pos = line.find(delimiter);
	if (pos == std::string::npos)
		throw std::runtime_error("invalid line: " + line);
	std::string first = line.substr(0, pos);
	std::string second = line.substr(pos + 1);
	return std::pair<std::string, std::string>(first, second);
}

std::string BitcoinExchange::trim(const std::string &str) {
	std::string::size_type left = str.find_first_not_of("\t\n\v\f\r ");
	if (left == std::string::npos)
		return "";
	std::string::size_type right = str.find_last_not_of("\t\n\v\f\r ");
	return str.substr(left, right - left + 1);
}

bool BitcoinExchange::isLeapYear(const int year)
{
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

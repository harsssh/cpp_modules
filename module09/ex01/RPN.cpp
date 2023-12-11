#include "RPN.hpp"
#include <sstream>

RPN::RPN() {}

RPN::RPN(const RPN &other) {
	(void) other;
}

RPN &RPN::operator=(const RPN &other) {
	(void) other;
	return *this;
}

RPN::~RPN() {}

#include <iostream>

int RPN::calculate(const std::string &str) throw(std::invalid_argument, std::runtime_error) {
	std::stack<std::string> stack;
	std::istringstream iss(str);
	std::string token;

	while (!iss.eof()) {
		iss >> token;
		if (!isValidToken(token))
			throw std::invalid_argument("Invalid token");

		if (isNumber(token))
			stack.push(token);
		if (isOperator(token)) {
			if (stack.size() < 2)
				throw std::runtime_error("Not enough operands");
			std::string op1 = stack.top();
			stack.pop();
			std::string op2 = stack.top();
			stack.pop();

			// exception never thrown
			int i1 = s2i(op1);
			int i2 = s2i(op2);

			int result;
			switch (token[0]) {
				case '+':
					result = i2 + i1;
					break;
				case '-':
					result = i2 - i1;
					break;
				case '*':
					result = i2 * i1;
					break;
				case '/':
					if (i1 == 0)
						throw std::runtime_error("Division by zero");
					result = i2 / i1;
					break;
			}
			stack.push(i2s(result));
		}
	}

	if (stack.size() != 1)
		throw std::runtime_error("Invalid expression");

	return s2i(stack.top());
}

bool RPN::isValidToken(const std::string &token) {
	if (token.length() != 1)
		return false;
	if (std::isdigit(token[0]))
		return true;
	if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')
		return true;
	return false;
}

// token is a single character
bool RPN::isNumber(const std::string &token) {
	return std::isdigit(token[0]);
}

// token is a single character
bool RPN::isOperator(const std::string &token) {
	return token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/';
}

// simple string to int conversion
int RPN::s2i(const std::string &str) throw(std::invalid_argument) {
	std::istringstream iss(str);
	int i;
	iss >> i;
	if (iss.fail())
		throw std::invalid_argument("Invalid argument");
	return i;
}

std::string RPN::i2s(int i) {
	std::ostringstream oss;
	oss << i;
	return oss.str();
}

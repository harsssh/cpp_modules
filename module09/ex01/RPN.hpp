#ifndef CPP_MODULES_RPN_HPP
#define CPP_MODULES_RPN_HPP

#include <string>
#include <stack>
#include <stdexcept>

class RPN {
public:
	RPN();

	RPN(const RPN &other);

	RPN &operator=(const RPN &other);

	~RPN();

	static int calculate(const std::string &str) throw(std::invalid_argument, std::runtime_error);

private:
	static bool isValidToken(const std::string &token);

	static bool isNumber(const std::string &token);

	static bool isOperator(const std::string &token);

	static int s2i(const std::string &str) throw(std::invalid_argument);

	static std::string i2s(int i);
};

#endif //CPP_MODULES_RPN_HPP

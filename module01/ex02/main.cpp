#include <iostream>

int main() {
	const std::string str = "HI THIS IS BRAIN";
	const std::string *ptr = &str;
	const std::string &ref = str;

	std::cout << "address of str: " << &str << std::endl;
	std::cout << "address of ptr: " << ptr << std::endl;
	std::cout << "address of ref: " << &ref << std::endl;

	std::cout << "value of str: " << str << std::endl;
	std::cout << "value of ptr: " << *ptr << std::endl;
	std::cout << "value of ref: " << ref << std::endl;
}

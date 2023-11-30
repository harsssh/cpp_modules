#include <iostream>

int main(int argc, char **argv) {
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int i = 1; i < argc; i++) {
		std::string arg = argv[i];
		std::transform(arg.begin(), arg.end(), arg.begin(), toupper);
		std::cout << arg;
	}
	std::cout << std::endl;
}
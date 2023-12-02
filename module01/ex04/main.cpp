#include <iostream>
#include <fstream>
#include <sstream>

std::string replace_str(const std::string &str, const std::string &s1, const std::string &s2) {
	std::stringstream ss;
	std::string::size_type pos;
	std::string::size_type prev = 0;
	while ((pos = str.find(s1, prev)) != std::string::npos) {
		ss << str.substr(prev, pos - prev) << s2;
		prev = pos + s1.size();
	}
	// add the rest of the string
	ss << str.substr(prev);
	return ss.str();
}

int createReplacedFile(const std::string &filename, const std::string &s1, const std::string &s2) {
	std::ifstream ifs(filename);
	if (!ifs.is_open()) {
		std::cerr << "Failed to open file: " << filename << std::endl;
		return 1;
	}
	std::ofstream ofs(filename + ".replace");
	if (!ofs.is_open()) {
		std::cerr << "Failed to open file: " << filename + ".replace" << std::endl;
		return 1;
	}

	// If you process the file line by line using `getline`,
	// it does not work correctly when there is no newline at the end of the file.
	std::stringstream ss;
	ss << ifs.rdbuf();
	std::string content = ss.str();
	ofs << replace_str(content, s1, s2);
	ifs.close();
	ofs.close();
	return 0;
}

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <filename> <search string> <replace string>" << std::endl;
		return 1;
	}
	return createReplacedFile(argv[1], argv[2], argv[3]);
}

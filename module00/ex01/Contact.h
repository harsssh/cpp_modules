#ifndef CPP_MODULES_CONTACT_H
#define CPP_MODULES_CONTACT_H

#include <string>

class Contact {
private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

public:
	Contact();

	Contact(const std::string &first_name, const std::string &last_name, const std::string &nickname,
			const std::string &phone_number, const std::string &darkest_secret);

	Contact(const Contact &c);

	~Contact();

	Contact &operator=(const Contact &c);

	std::string get_first_name();

	std::string get_last_name();

	std::string get_nickname();

	void print_contact();

	bool is_valid();
};

#endif //CPP_MODULES_CONTACT_H

#ifndef CPP_MODULES_PHONEBOOK_H
#define CPP_MODULES_PHONEBOOK_H

#include "Contact.h"

class PhoneBook {
private:
	const static int maxContacts = 8;
	const static int maxFieldWidth = 10;
	const static char tableDelimiter = '|';
	Contact contacts[maxContacts];
	int contact_count;
	int overwrite_index;

	static void print_header();

	void print_phonebook_row(int);

	static std::string truncate_string(const std::string &);

public:
	PhoneBook();

	PhoneBook &operator=(const PhoneBook &);

	int get_contact_count() const;

	void add_contact(const Contact &);

	void print_phonebook();

	void print_contact(int);
};

#endif //CPP_MODULES_PHONEBOOK_H

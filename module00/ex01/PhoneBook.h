#ifndef CPP_MODULES_PHONEBOOK_H
#define CPP_MODULES_PHONEBOOK_H

#include "Contact.h"

class PhoneBook {
private:
	const static int MAX_CONTACTS = 8;
	const static int MAX_FIELD_WIDTH = 10;
	const static char TABLE_DELIMITER = '|';
	Contact contacts[MAX_CONTACTS];
	int contact_count;
	int overwrite_index;

	static void print_header();

	void print_phonebook_row(int);

	static std::string truncate_string(const std::string &);

public:
	PhoneBook();

	PhoneBook(const PhoneBook &);

	~PhoneBook();

	PhoneBook &operator=(const PhoneBook &);

	int get_contact_count() const;

	void add_contact(const Contact &);

	void print_phonebook();

	void print_contact(int);
};

#endif //CPP_MODULES_PHONEBOOK_H

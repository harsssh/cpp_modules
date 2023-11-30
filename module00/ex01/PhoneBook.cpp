#include "PhoneBook.h"
#include "utils.h"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : contact_count(0), overwrite_index(0) {}

PhoneBook::PhoneBook(const PhoneBook &b) : contact_count(0), overwrite_index(0) {
	*this = b;
}

PhoneBook::~PhoneBook() {}

PhoneBook &PhoneBook::operator=(const PhoneBook &b) {
	if (this == &b)
		return (*this);
	this->overwrite_index = b.overwrite_index;
	this->contact_count = b.contact_count;
	for (int i = 0; i < b.contact_count; i++) {
		this->contacts[i] = b.contacts[i];
	}
	return *this;
}

void PhoneBook::add_contact(const Contact &contact) {
	if (this->overwrite_index >= PhoneBook::MAX_CONTACTS)
		this->overwrite_index = 0;
	this->contacts[this->overwrite_index] = contact;
	++this->overwrite_index;
	if (this->contact_count < PhoneBook::MAX_CONTACTS)
		++this->contact_count;
}

void PhoneBook::print_header() {
	const std::string columns[] = {
			"index",
			"first name",
			"last name",
			"nickname"
	};
	for (int i = 0; i < 4; i++) {
		std::cout << std::setw(PhoneBook::MAX_FIELD_WIDTH) << PhoneBook::truncate_string(columns[i]);
		if (i < 3)
			std::cout << PhoneBook::TABLE_DELIMITER;
	}
}

void PhoneBook::print_phonebook_row(int row) {
	if (row < 0 || row >= PhoneBook::MAX_CONTACTS || row >= this->contact_count)
		return;
	Contact contact = this->contacts[row];
	const std::string fields[] = {
			to_string(row),
			contact.get_first_name(),
			contact.get_last_name(),
			contact.get_nickname()
	};
	for (int i = 0; i < 4; i++) {
		std::cout << std::setw(PhoneBook::MAX_FIELD_WIDTH) << PhoneBook::truncate_string(fields[i]);
		if (i < 3)
			std::cout << PhoneBook::TABLE_DELIMITER;
	}
}

void PhoneBook::print_phonebook() {
	this->print_header();
	std::cout << std::endl;
	for (int i = 0; i < this->contact_count; i++) {
		this->print_phonebook_row(i);
		std::cout << std::endl;
	}
}

std::string PhoneBook::truncate_string(const std::string &str) {
	if (str.length() <= PhoneBook::MAX_FIELD_WIDTH) {
		return str;
	}

	std::string truncated = str.substr(0, PhoneBook::MAX_FIELD_WIDTH - 1);
	truncated.append(".");
	return truncated;
}

void PhoneBook::print_contact(int i) {
	if (i < 0 || i >= PhoneBook::MAX_CONTACTS || i >= this->contact_count) {
		std::cout << "Invalid index" << std::endl;
		return;
	}
	this->contacts[i].print_contact();
}

int PhoneBook::get_contact_count() const {
	return this->contact_count;
}


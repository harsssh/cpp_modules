#include "Contact.h"
#include <iostream>

Contact::Contact() {}

Contact::Contact(const std::string &first_name, const std::string &last_name, const std::string &nickname,
				 const std::string &phone_number, const std::string &darkest_secret)
		: first_name(first_name), last_name(last_name), nickname(nickname),
		  phone_number(phone_number), darkest_secret(darkest_secret) {}

Contact &Contact::operator=(const Contact &c) {
	if (this == &c)
		return (*this);
	this->first_name = c.first_name;
	this->last_name = c.last_name;
	this->nickname = c.nickname;
	this->phone_number = c.phone_number;
	this->darkest_secret = c.darkest_secret;
	return *this;
}

std::string Contact::get_first_name() {
	return this->first_name;
}

std::string Contact::get_last_name() {
	return this->last_name;
}

std::string Contact::get_nickname() {
	return this->nickname;
}

void Contact::print_contact() {
	std::cout << "First name: " << this->first_name << std::endl;
	std::cout << "Last name: " << this->last_name << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Phone number: " << this->phone_number << std::endl;
	std::cout << "Darkest secret: " << this->darkest_secret << std::endl;
}

bool Contact::is_valid() {
	return !this->first_name.empty() && !this->last_name.empty() && !this->nickname.empty() &&
		   !this->phone_number.empty() && !this->darkest_secret.empty();
}

#include "Contact.h"
#include "PhoneBook.h"
#include <string>
#include <iostream>
#include <limits>

typedef enum {
	CMD_UNKNOWN,
	CMD_ADD,
	CMD_SEARCH,
	CMD_EXIT
} command_t;

static void show_all_commands() {
	std::cout << "Available commands:" << std::endl;
	std::cout << "ADD: add a new contact"
			  << " / SEARCH: search for a contact"
			  << " / EXIT: exit the program"
			  << std::endl;
}

static std::string getline_with_prompt(const std::string &prompt) {
	std::string line;
	std::cout << prompt;
	std::getline(std::cin, line);
	if (std::cin.fail() || std::cin.eof())
		std::exit(1);
	return line;
}

static command_t get_command() {
	std::string command = getline_with_prompt("Enter a command: ");
	if (command == "ADD")
		return CMD_ADD;
	else if (command == "SEARCH")
		return CMD_SEARCH;
	else if (command == "EXIT")
		return CMD_EXIT;
	else
		return CMD_UNKNOWN;
}


static void handle_add_command(PhoneBook &phone_book) {
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	first_name = getline_with_prompt("Enter first name: ");
	last_name = getline_with_prompt("Enter last name: ");
	nickname = getline_with_prompt("Enter nickname: ");
	phone_number = getline_with_prompt("Enter phone number: ");
	darkest_secret = getline_with_prompt("Enter darkest secret: ");

	Contact contact(first_name, last_name, nickname, phone_number, darkest_secret);
	if (!contact.is_valid()) {
		std::cout << "Invalid contact" << std::endl;
		return;
	}
	phone_book.add_contact(contact);
}

static void handle_search_command(PhoneBook &phone_book) {
	if (phone_book.get_contact_count() == 0) {
		std::cout << "Phone book is empty" << std::endl;
		return;
	}

	phone_book.print_phonebook();

	int index;
	std::cout << "Enter an index: ";
	std::cin >> index;
	// ignore the rest of the line
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (std::cin.fail()) {
		std::cout << "Invalid index" << std::endl;
		std::cin.clear();
		return;
	}
	phone_book.print_contact(index);
}

int main() {
	PhoneBook phone_book;

	show_all_commands();
	while (true) {
		command_t command = get_command();
		if (std::cin.eof())
			break;
		bool exit_flag = false;
		switch (command) {
			case CMD_ADD:
				handle_add_command(phone_book);
				break;
			case CMD_SEARCH:
				handle_search_command(phone_book);
				break;
			case CMD_EXIT:
				exit_flag = true;
				break;
			default:
				break;
		}
		if (exit_flag)
			break;
	}
}

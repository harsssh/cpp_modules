#include "Intern.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern &other) {
	*this = other;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &other) {
	if (this != &other) {}
	return *this;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) {
	// array of member function pointer
	AForm *(Intern::*makeFormFunctions[])(const std::string &) = {
			&Intern::makeShrubberyCreationForm,
			&Intern::makeRobotomyRequestForm,
			&Intern::makePresidentialPardonForm
	};
	std::string formNames[] = {
			"shrubbery creation",
			"robotomy request",
			"presidential pardon"
	};

	for (int i = 0; i < 3; ++i) {
		if (formName == formNames[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*makeFormFunctions[i])(target);
		}
	}
	std::cout << "Intern cannot create " << formName << std::endl;
	return NULL;
}

AForm *Intern::makeShrubberyCreationForm(const std::string &target) {
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomyRequestForm(const std::string &target) {
	return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidentialPardonForm(const std::string &target) {
	return new PresidentialPardonForm(target);
}

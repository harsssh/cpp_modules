#ifndef CPP_MODULES_INTERN_H
#define CPP_MODULES_INTERN_H

#include "AForm.h"

class Intern {
public:
	Intern();

	Intern(const Intern &other);

	~Intern();

	Intern &operator=(const Intern &other);

	AForm *makeForm(const std::string &formName, const std::string &target);

private:
	AForm *makeShrubberyCreationForm(const std::string &target);
	AForm *makeRobotomyRequestForm(const std::string &target);
	AForm *makePresidentialPardonForm(const std::string &target);
};

#endif //CPP_MODULES_INTERN_H

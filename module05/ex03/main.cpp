#include <iostream>
#include "Bureaucrat.h"
#include "AForm.h"
#include "Intern.h"

void createFormAndExecute(const std::string &formName, const std::string &target) {
	Intern intern;
	AForm *form = intern.makeForm(formName, target);
	if (!form)
		return;
	std::cout << *form << std::endl;

	std::cout << "Signs and executes form" << std::endl;
	Bureaucrat bureaucrat("B1", 1);
	bureaucrat.signForm(*form);
	bureaucrat.executeForm(*form);

	delete form;
}

int main() {
	std::cout << "[Test ShrubberyCreationForm]" << std::endl;
	createFormAndExecute("shrubbery creation", "F1");

	std::cout << std::endl;
	std::cout << "[Test RobotomyRequestForm]" << std::endl;
	createFormAndExecute("robotomy request", "F2");

	std::cout << std::endl;
	std::cout << "[Test PresidentialPardonForm]" << std::endl;
	createFormAndExecute("presidential pardon", "F3");

	std::cout << std::endl;
	std::cout << "[Test Invalid Form]" << std::endl;
	createFormAndExecute("invalid form", "F4");
}
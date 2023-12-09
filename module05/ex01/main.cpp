#include <iostream>
#include "Bureaucrat.h"
#include "Form.h"

void testNormal() {
	std::cout << "Create bureaucrat with grade 42" << std::endl;
	Bureaucrat bureaucrat("B1", 42);
	std::cout << bureaucrat << std::endl;

	std::cout << "Create form with gradeToSign 42 and gradeToExecute 42" << std::endl;
	Form form("F1", 42, 42);
	std::cout << form << std::endl;

	std::cout << "Sign form" << std::endl;
	bureaucrat.signForm(form);
	std::cout << form << std::endl;

	std::cout << "Sign form again" << std::endl;
	bureaucrat.signForm(form);
	std::cout << form << std::endl;
}

void testCannotSign() {
	std::cout << "Create bureaucrat with grade 43" << std::endl;
	Bureaucrat bureaucrat("B1", 43);

	std::cout << "Create form with gradeToSign 42 and gradeToExecute 42" << std::endl;
	Form form("F1", 42, 42);
	std::cout << form << std::endl;

	std::cout << "Sign form" << std::endl;
	bureaucrat.signForm(form);

	std::cout << "Increment bureaucrat's grade" << std::endl;
	bureaucrat.incrementGrade();

	std::cout << "Sign form again" << std::endl;
	bureaucrat.signForm(form);
	std::cout << form << std::endl;
}

// cannot create form because the grade is too high
void testTooHighGrade() {
	try {
		// gradeToSign is too high
		std::cout << "Create form with gradeToSign 0 and gradeToExecute 42" << std::endl;
		Form form("F1", 0, 42);
	} catch (Form::GradeTooHighException &e) {
		std::cout << "GradeTooHighException caught" << std::endl;
	}

	try {
		// gradeToExecute is too high
		std::cout << "Create form with gradeToSign 42 and gradeToExecute 0" << std::endl;
		Form form("F1", 42, 0);
	} catch (Form::GradeTooHighException &e) {
		std::cout << "GradeTooHighException caught" << std::endl;
	}
}

void testTooLowGrade() {
	try {
		// gradeToSign is too low
		std::cout << "Create form with gradeToSign 151 and gradeToExecute 42" << std::endl;
		Form form("F1", 151, 42);
	} catch (Form::GradeTooLowException &e) {
		std::cout << "GradeTooLowException caught" << std::endl;
	}

	try {
		// gradeToExecute is too low
		std::cout << "Create form with gradeToSign 42 and gradeToExecute 151" << std::endl;
		Form form("F1", 42, 151);
	} catch (Form::GradeTooLowException &e) {
		std::cout << "GradeTooLowException caught" << std::endl;
	}
}

int main() {
	std::cout << "[testNormal]" << std::endl;
	testNormal();

	std::cout << "[testCannotSign]" << std::endl;
	testCannotSign();

	std::cout << std::endl;
	std::cout << "[testTooHighGrade]" << std::endl;
	testTooHighGrade();

	std::cout << std::endl;
	std::cout << "[testTooLowGrade]" << std::endl;
	testTooLowGrade();
}

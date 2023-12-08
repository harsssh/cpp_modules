#include <iostream>
#include "Bureaucrat.h"

void testNormal() {
	std::cout << "Create bureaucrat with grade 42" << std::endl;
	Bureaucrat bureaucrat("B1", 42);
	std::cout << bureaucrat << std::endl;

	std::cout << "Increment grade" << std::endl;
	bureaucrat.incrementGrade();
	std::cout << bureaucrat << std::endl;

	std::cout << "Decrement grade" << std::endl;
	bureaucrat.decrementGrade();
	std::cout << bureaucrat << std::endl;
}

void testTooHighGrade() {
	std::cout << "Create bureaucrat with grade 0" << std::endl;
	try {
		Bureaucrat bureaucrat("B1", 0);
		std::cout << bureaucrat << std::endl;
	} catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << "GradeTooHighException caught" << std::endl;
	}

	// create bureaucrat with grade 1, then increment
	std::cout << "Create bureaucrat with grade 1" << std::endl;
	Bureaucrat bureaucrat("B2", 1);
	std::cout << bureaucrat << std::endl;
	try {
		std::cout << "Increment grade" << std::endl;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;
	} catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << "GradeTooHighException caught" << std::endl;
	}
}

void testTooLowGrade() {
	std::cout << "Create bureaucrat with grade 151" << std::endl;
	try {
		Bureaucrat bureaucrat("B1", 151);
		std::cout << bureaucrat << std::endl;
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << "GradeTooLowException caught" << std::endl;
	}

	// create bureaucrat with grade 150, then decrement
	std::cout << "Create bureaucrat with grade 150" << std::endl;
	Bureaucrat bureaucrat("B2", 150);
	std::cout << bureaucrat << std::endl;
	try {
		std::cout << "Decrement grade" << std::endl;
		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << "GradeTooLowException caught" << std::endl;
	}
}

int main() {
	std::cout << "[testNormal]" << std::endl;
	testNormal();

	std::cout << std::endl;
	std::cout << "[testTooHighGrade]" << std::endl;
	testTooHighGrade();

	std::cout << std::endl;
	std::cout << "[testTooLowGrade]" << std::endl;
	testTooLowGrade();
}

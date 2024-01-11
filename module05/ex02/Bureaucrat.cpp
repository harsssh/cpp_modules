#include <iostream>
#include "Bureaucrat.h"
#include "AForm.h"

Bureaucrat::Bureaucrat() : name_("anonymous"), grade_(Bureaucrat::minGrade_) {}

Bureaucrat::Bureaucrat(const std::string &name) : name_(name), grade_(Bureaucrat::minGrade_) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name_(name) {
	setGrade(grade);
}

Bureaucrat::~Bureaucrat() {}

// other.grade_ must be valid
Bureaucrat::Bureaucrat(const Bureaucrat &other) : name_(other.name_), grade_(other.grade_) {}

// name_ is const, so we can't assign it
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other) {
		grade_ = other.grade_;
	}
	return *this;
}

const std::string &Bureaucrat::getName() const {
	return name_;
}

int Bureaucrat::getGrade() const {
	return grade_;
}

void Bureaucrat::setGrade(int grade) {
	if (Bureaucrat::isTooHighGrade(grade))
		throw GradeTooHighException();
	if (Bureaucrat::isTooLowGrade(grade))
		throw GradeTooLowException();
	grade_ = grade;
}

bool Bureaucrat::isTooHighGrade(int grade) {
	return grade < Bureaucrat::maxGrade_;
}

bool Bureaucrat::isTooLowGrade(int grade) {
	return grade > Bureaucrat::minGrade_;
}

// grade_ is valid, so grade_ - 1 must not overflow
void Bureaucrat::incrementGrade() {
	if (Bureaucrat::isTooHighGrade(this->getGrade() - 1))
		throw GradeTooHighException();
	--grade_;
}

// grade_ is valid, so grade_ + 1 must not overflow
void Bureaucrat::decrementGrade() {
	if (Bureaucrat::isTooLowGrade(this->getGrade() + 1))
		throw GradeTooLowException();
	++grade_;
}

void Bureaucrat::signForm(AForm &form) const {
	if (form.isSigned()) {
		std::cout << name_ << " couldn't sign " << form.getName()
				  << " because it's already signed" << std::endl;
		return;
	}

	try {
		form.beSigned(*this);
		std::cout << name_ << " signed " << form.getName() << std::endl;
	} catch (AForm::GradeTooLowException &e) {
		std::cout << name_ << " couldn't sign " << form.getName()
				  << " because grade was too low" << std::endl;
	}
}

void Bureaucrat::executeForm(AForm &form) const {
	try {
		form.execute(*this);
		std::cout << name_ << " executed " << form.getName() << std::endl;
	} catch (AForm::GradeTooLowException &e) {
		std::cout << name_ << " couldn't execute " << form.getName()
				  << " because grade was too low" << std::endl;
	} catch (AForm::FormNotSignedException &e) {
		std::cout << name_ << " couldn't execute " << form.getName()
				  << " because it's not signed" << std::endl;
	} catch (std::runtime_error &e) {
		std::cout << name_ << " couldn't execute " << form.getName()
				  << " because " << e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "grade is too low";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}
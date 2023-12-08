#include "Bureaucrat.h"

Bureaucrat::Bureaucrat(): name_("anonymous"), grade_(Bureaucrat::minGrade_) {}

Bureaucrat::Bureaucrat(const std::string &name) : name_(name), grade_(Bureaucrat::minGrade_) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) throw(GradeTooHighException, GradeTooLowException)
		: name_(name) {
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

void Bureaucrat::setGrade(int grade) throw(GradeTooHighException, GradeTooLowException) {
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
void Bureaucrat::incrementGrade() throw(GradeTooHighException) {
	if (Bureaucrat::isTooHighGrade(this->getGrade() - 1))
		throw GradeTooHighException();
	--grade_;
}

// grade_ is valid, so grade_ + 1 must not overflow
void Bureaucrat::decrementGrade() throw(GradeTooLowException) {
	if (Bureaucrat::isTooLowGrade(this->getGrade() + 1))
		throw GradeTooLowException();
	++grade_;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return os;
}
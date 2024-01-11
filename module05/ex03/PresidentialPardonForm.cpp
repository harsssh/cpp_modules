#include "PresidentialPardonForm.h"
#include "Bureaucrat.h"
#include <cstdlib>
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
		: AForm("PresidentialPardonForm", gradeToSign_, gradeToExecute_), target_("default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
		: AForm("PresidentialPardonForm", gradeToSign_, gradeToExecute_), target_(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	AForm::operator=(other);
	return *this;
}

const std::string &PresidentialPardonForm::getTarget() const {
	return target_;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	if (!isSigned())
		throw FormNotSignedException();
	if (!isEnoughGradeToExecute(executor.getGrade()))
		throw GradeTooLowException();

	std::cout << target_ << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

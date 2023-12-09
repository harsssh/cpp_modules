#include "RobotomyRequestForm.h"
#include "Bureaucrat.h"
#include <cstdlib>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm()
		: AForm("RobotomyRequestForm", gradeToSign_, gradeToExecute_), target_("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
		: AForm("RobotomyRequestForm", gradeToSign_, gradeToExecute_), target_(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	AForm::operator=(other);
	return *this;
}

const std::string &RobotomyRequestForm::getTarget() const {
	return target_;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
throw(FormNotSignedException, GradeTooLowException) {
	if (!isSigned())
		throw FormNotSignedException();
	if (!isEnoughGradeToExecute(executor.getGrade()))
		throw GradeTooLowException();

	std::srand(std::time(NULL));
	if (std::rand() % 2 == 0)
		std::cout << target_ << " has been robotomized successfully" << std::endl;
	else
		std::cout << target_ << " robotomization failed" << std::endl;
}

#ifndef CPP_MODULES_ROBOTOMYREQUESTFORM_H
#define CPP_MODULES_ROBOTOMYREQUESTFORM_H

#include "AForm.h"

class RobotomyRequestForm : public AForm {
public:
	RobotomyRequestForm();

	RobotomyRequestForm(const std::string &target);

	RobotomyRequestForm(const RobotomyRequestForm &other);

	virtual ~RobotomyRequestForm();

	RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

	const std::string &getTarget() const;

	virtual void
	execute(const Bureaucrat &executor) const throw(FormNotSignedException, GradeTooLowException);

private:
	static const int gradeToSign_ = 72;
	static const int gradeToExecute_ = 45;
	const std::string target_;
};

#endif //CPP_MODULES_ROBOTOMYREQUESTFORM_H

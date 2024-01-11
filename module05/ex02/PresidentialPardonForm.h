#ifndef CPP_MODULES_PRESIDENTIALPARDONFORM_H
#define CPP_MODULES_PRESIDENTIALPARDONFORM_H

#include "AForm.h"

class PresidentialPardonForm : public AForm {
public:
	PresidentialPardonForm();

	PresidentialPardonForm(const std::string &target);

	PresidentialPardonForm(const PresidentialPardonForm &other);

	virtual ~PresidentialPardonForm();

	PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

	const std::string &getTarget() const;

	virtual void execute(const Bureaucrat &executor) const;

private:
	static const int gradeToSign_ = 25;
	static const int gradeToExecute_ = 5;
	const std::string target_;
};

#endif //CPP_MODULES_PRESIDENTIALPARDONFORM_H

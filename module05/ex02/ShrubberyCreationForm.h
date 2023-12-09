#ifndef CPP_MODULES_SHRUBBERYCREATIONFORM_H
#define CPP_MODULES_SHRUBBERYCREATIONFORM_H

#include "AForm.h"

class ShrubberyCreationForm : public AForm {
public:
	ShrubberyCreationForm();

	ShrubberyCreationForm(const std::string &target);

	ShrubberyCreationForm(const ShrubberyCreationForm &other);

	virtual ~ShrubberyCreationForm();

	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

	const std::string &getTarget() const;

	virtual void
	execute(const Bureaucrat &executor) const throw(FormNotSignedException, GradeTooLowException, std::runtime_error);

private:
	static const int gradeToSign_ = 145;
	static const int gradeToExecute_ = 137;
	const std::string target_;
};

#endif //CPP_MODULES_SHRUBBERYCREATIONFORM_H

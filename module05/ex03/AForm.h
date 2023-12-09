#ifndef CPP_MODULES_AFORM_H
#define CPP_MODULES_AFORM_H

#include <string>

// forward declaration
class Bureaucrat;

class AForm {
public:
	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class FormNotSignedException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	AForm();

	AForm(const std::string &name, int gradeToSign,
		 int gradeToExecute) throw(GradeTooHighException, GradeTooLowException);


	AForm(const AForm &other);

	virtual ~AForm();

	AForm &operator=(const AForm &other);

	const std::string &getName() const;

	int getGradeToSign() const;

	int getGradeToExecute() const;

	bool isSigned() const;

	void beSigned(const Bureaucrat &bureaucrat) throw (GradeTooLowException);

	bool isEnoughGradeToSign(int grade) const;

	bool isEnoughGradeToExecute(int grade) const;

	virtual void execute(const Bureaucrat &executor) const = 0;

private:
	const std::string name_;
	const int gradeToSign_;
	const int gradeToExecute_;
	bool isSigned_;

	void setIsSigned(bool isSigned);

	static bool isTooHighGrade(int grade);

	static bool isTooLowGrade(int grade);
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif //CPP_MODULES_AFORM_H

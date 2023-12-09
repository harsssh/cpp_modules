#ifndef CPP_MODULES_FORM_H
#define CPP_MODULES_FORM_H

#include <string>

// forward declaration
class Bureaucrat;

class Form {
public:
	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

	Form();

	Form(const std::string &name, int gradeToSign,
		 int gradeToExecute) throw(GradeTooHighException, GradeTooLowException);


	Form(const Form &other);

	virtual ~Form();

	Form &operator=(const Form &other);

	const std::string &getName() const;

	int getGradeToSign() const;

	int getGradeToExecute() const;

	bool isSigned() const;

	void beSigned(const Bureaucrat &bureaucrat) throw(GradeTooLowException);

private:
	const std::string name_;
	const int gradeToSign_;
	const int gradeToExecute_;
	bool isSigned_;

	void setIsSigned(bool isSigned);

	static bool isTooHighGrade(int grade);

	static bool isTooLowGrade(int grade);

	bool isEnoughGradeToSign(int grade) const;

	bool isEnoughGradeToExecute(int grade) const;
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif //CPP_MODULES_FORM_H

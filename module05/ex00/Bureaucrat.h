#ifndef CPP_MODULES_BUREAUCRAT_H
#define CPP_MODULES_BUREAUCRAT_H

#include <string>
#include <ostream>

class Bureaucrat {
private:
	static const int maxGrade_ = 1;
	static const int minGrade_ = 150;
	const std::string name_;
	int grade_;

public:
	class GradeTooHighException : public std::exception {
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
		virtual const char *what() const throw();
	};

	Bureaucrat();

	Bureaucrat(const std::string &name);

	Bureaucrat(const std::string &name, int grade) throw(GradeTooHighException, GradeTooLowException);

	virtual ~Bureaucrat();

	Bureaucrat(const Bureaucrat &other);

	Bureaucrat &operator=(const Bureaucrat &other);

	void setGrade(int grade) throw(GradeTooHighException, GradeTooLowException);

	const std::string &getName() const;

	int getGrade() const;

	static bool isTooHighGrade(int grade);

	static bool isTooLowGrade(int grade);

	void incrementGrade() throw(GradeTooHighException);

	void decrementGrade() throw(GradeTooLowException);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif //CPP_MODULES_BUREAUCRAT_H

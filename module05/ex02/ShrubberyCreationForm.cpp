#include "ShrubberyCreationForm.h"
#include "Bureaucrat.h"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm()
		: AForm("ShrubberyCreationForm", gradeToSign_, gradeToExecute_), target_("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
		: AForm("ShrubberyCreationForm", gradeToSign_, gradeToExecute_), target_(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	AForm::operator=(other);
	return *this;
}

const std::string &ShrubberyCreationForm::getTarget() const {
	return target_;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	if (!isSigned())
		throw FormNotSignedException();
	if (!isEnoughGradeToExecute(executor.getGrade()))
		throw GradeTooLowException();

	// NOTE: 直接 std::string を渡すとコンパイルできない環境がある
	const std::string fileName = target_ + "_shrubbery";
	std::ofstream file(fileName.c_str());
	if (!file.is_open())
	{
		std::perror("foo");
		throw std::runtime_error("cannot open file");
	}
	std::string shrubbery =
			"     ^^^   \n"
			"    ^^^^   \n"
			"   ^^^^^   \n"
			"  ^^^^^^^  \n"
			" ^^^^^^^^^ \n"
			"^^^^^^^^^^^\n";
	file << shrubbery;
	file.close();
}

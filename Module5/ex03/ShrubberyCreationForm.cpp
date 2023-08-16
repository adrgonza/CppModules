#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("SCreation Form", 137, 145)
{
	this->target = "home";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("SCreation Form", 137, 145)
{
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other.getName(), other.getGradeExec(), other.getGradeSign())
{
	this->target = other.target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		this->target = other.target;
	}
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getSign() == false)
		throw AFormNotSigned();
	if (executor.getGrade() >= this->getGradeExec())
		throw GradeTooLowException();

	std::string filename = this->target + "_shrubbery";
	std::ofstream ofs(filename);
	if (!ofs.is_open())
	{
		std::cerr << "Unable to open file: " << filename << std::endl;
		return;
	}
	ofs << "*this is a tree*   *this is another tree*   *this is another tree*   *this is another tree*" << std::endl;
	ofs.close();
}

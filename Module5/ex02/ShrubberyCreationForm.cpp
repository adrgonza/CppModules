#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
	this->target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
{
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{

}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (this->getSign() == false)
        throw AFormNotSigned();
    if (executor.getGrade() <= this->getGradeExec())
        throw GradeTooLowException();

	std::string filename = this->target + "_shrubbery";
	std::ofstream ofs(filename);
	if (!ofs.is_open())
	{
		std::cerr << "Unable to open file: " << filename << std::endl;
		return;
	}
	ofs << "*this is a tree* *this is another tree* *this is another tree* *this is another tree*" << std::endl;
	ofs.close();
}
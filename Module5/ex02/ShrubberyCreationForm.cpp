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

void ShrubberyCreationForm::createFile() const
{
	std::string filename = this->target + "_shrubbery";
	std::ofstream ofs(filename);
	if (!ofs.is_open())
	{
		std::cerr << "Unable to open file: " << filename << std::endl;
		return;
	}
	ofs << "ASCII trees content goes here..." << std::endl;
	ofs.close();
}

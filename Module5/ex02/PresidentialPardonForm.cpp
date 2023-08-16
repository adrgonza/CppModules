#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("home", 5, 25)
{
	this->_target = "home";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("home", 5, 25)
{
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other.getName(), other.getGradeExec(), other.getGradeSign())
{
	this->_target = other._target;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		this->_target = other._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	if (this->getSign() == false)
		throw AFormNotSigned();
	if (executor.getGrade() >= this->getGradeExec())
		throw GradeTooLowException();
	std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RRequest Form", 45, 72)
{
	this->_target = "home";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)  : AForm("RRequest Form", 45, 72)
{
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other.getName(), other.getGradeExec(), other.getGradeSign())
{
	this->_target = other._target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		this->_target = other._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getSign() == false)
		throw AFormNotSigned();
	if (executor.getGrade() >= this->getGradeExec())
		throw GradeTooLowException();
	std::cout << "rat-a-tat-tat" << std::endl;

	static int random = 0;
	if (random == 0)
	{
		std::cout << this->_target << " has been robotomized successfully!" << std::endl;
		random = 1;
	}
	else if (random == 1)
	{
		std::cout << this->_target << " robotomy failed!" << std::endl;
		random = 0;
	}
}

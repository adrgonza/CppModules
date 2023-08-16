#include "AForm.hpp"

AForm::AForm() : _name("default"), _gradeToExecute(30), _gradeToSign(20)
{
	this->_sign = false;
}

AForm::AForm(std::string name) : _name(name), _gradeToExecute(30), _gradeToSign(20)
{
	this->_sign = false;
}

AForm::AForm(const std::string name, const int gradeExec, const int gradeSign) : _name(name), _gradeToExecute(gradeExec), _gradeToSign(gradeSign)
{
	this->_sign = 0;
	if (this->_gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (this->_gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	if (this->_gradeToSign < 1)
		throw AForm::GradeTooHighException();
	if (this->_gradeToSign > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other) : _name(other._name), _gradeToExecute(other._gradeToExecute), _gradeToSign(other._gradeToSign)
{
	this->_sign = other._sign;
}

AForm::~AForm()
{

}

const char * AForm::GradeTooLowException::what() const throw()
{
	return ("Error Grade is too low");
}

const char * AForm::GradeTooHighException::what() const throw()
{
	return ("Error Grade is too high");
}

const char * AForm::AFormAlredySigned::what() const throw()
{
	return ("Error AForm is alredy signed");
}

const char * AForm::AFormNotSigned::what() const throw()
{
	return ("Error AForm has not been signed yet");
}

std::string AForm::getName() const
{
	return (this->_name);
}

int AForm::getGradeSign() const
{
	return (this->_gradeToSign);
}

int AForm::getGradeExec() const
{
	return (this->_gradeToExecute);
}

bool AForm::getSign() const
{
	return (this->_sign);
}

void AForm::beSigned(Bureaucrat &Bureaucrat)
{
	if (Bureaucrat.getGrade() > this->_gradeToSign)
		throw Bureaucrat::GradeTooLowException();
	else if (this->_sign == true)
		throw AForm::AFormAlredySigned();
	else
		this->_sign = true;
}

AForm& AForm::operator=( const AForm &other )
{
	if (this != &other)
	{
		this->_sign = other._sign;
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& os, AForm& AForm)
{
	os << AForm.getName() << " grade to Sign: " << AForm.getGradeSign() << ", grade to Execute: " << AForm.getGradeExec() << std::endl;
	return (os);
}

#include "Form.hpp"

Form::Form() : _name("default"), _gradeToExecute(30), _gradeToSign(30)
{
	this->_sign = 0;
}

Form::Form(std::string name) : _name(name), _gradeToExecute(30), _gradeToSign(30)
{
	this->_sign = 0;
}

Form::Form(const std::string name, const int gradeExec, const int gradeSign) : _name(name), _gradeToExecute(gradeExec), _gradeToSign(gradeSign)
{
	this->_sign = 0;
}

Form::Form(const Form &other) : _name(other._name), _gradeToExecute(other._gradeToExecute), _gradeToSign(other._gradeToSign)
{
	this->_sign = other._sign;
}

Form::~Form()
{

}

const char * Form::GradeTooLowException::what() const throw()
{
	return ("Error Grade is too low");
}

const char * Form::GradeTooHighException::what() const throw()
{
	return ("Error Grade is too high");
}

std::string Form::getName() const
{
	return (this->_name);
}

int Form::getGradeSign() const
{
	return (this->_gradeToSign);
}

int Form::getGradeExec() const
{
	return (this->_gradeToExecute);
}

bool Form::getSign() const
{
	return (this->_sign);
}

void Form::beSigned(Bureaucrat &Bureaucrat)
{

	if (Bureaucrat.getGrade() < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (Bureaucrat.getGrade() > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_sign = true;

}

Form& Form::operator=( const Form &other )
{
	if (this != &other)
	{
		this->_sign = other._sign;
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& os, Form& Form)
{
	os << Form.getName() << ", Form grade to Sign: " << Form.getGradeSign() << ", Form grade to Execute: " << Form.getGradeExec() << std::endl;
	return (os);
}

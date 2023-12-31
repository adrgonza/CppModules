#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Unknown")
{
	this->grade = 30;
}

Bureaucrat::Bureaucrat(std::string name) : name(name)
{
	this->grade = 30;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	this->grade = grade;

	if (this->grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name)
{
	this->grade = other.grade;
}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat &other )
{
	if (this != &other)
	{
		this->grade = other.grade;
	}
	return (*this);
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

std::string Bureaucrat::getName() const
{
	return this->name;
}

void Bureaucrat::incrementGrade()
{
	if (this->grade < 2)
		throw GradeTooHighException();
	else
		this->grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->grade > 149)
		throw GradeTooLowException();
	else
		this->grade++;
}

void Bureaucrat::signAForm(AForm &AForm)
{
	try
	{
		AForm.beSigned(*this);
		std::cout << this->name << " signed " << AForm.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->name << " couldn’t sign '" << AForm.getName() << "' because: " << e.what() << std::endl;
	}
}

void Bureaucrat::execute(AForm const& Form)
{
	try
	{
		Form.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << ", failed to execute " << Form.getName() << std::endl;
		return;
	}
	std::cout << this->name << " executed " << Form.getName() <<  std::endl;
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Error Grade is too low");
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Error Grade is too high");
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& Bureaucrat)
{
	os << Bureaucrat.getName() << ", Bureaucrat grade: " << Bureaucrat.getGrade() << std::endl;
	return (os);
}

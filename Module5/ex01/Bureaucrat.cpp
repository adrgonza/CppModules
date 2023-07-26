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
	try
	{
		if (this->grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (this->grade > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception " << e.what() << std::endl;
	}
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
	try
	{
		if (this->grade < 2)
			throw GradeTooHighException();
		else
			this->grade--;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception " << e.what() << std::endl;
	}

}

void Bureaucrat::decrementGrade()
{
	try
	{
		if (this->grade > 149)
			throw GradeTooLowException();
		else
			this->grade++;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception " << e.what() << std::endl;
	}

}

void Bureaucrat::signForm(Form &Form)
{
	try
	{
		Form.beSigned(*this);
		std::cout << this->name << " signed " << Form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->name << " couldn’t sign " << Form.getName() << "because " << e.what() << std::endl;
	}
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

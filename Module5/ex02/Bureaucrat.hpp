#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);

		class GradeTooHighException : public std::exception
		{
			public:
				const char * what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char * what() const throw();
		};

		~Bureaucrat();

		Bureaucrat& operator=( const Bureaucrat &other );

		std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void signAForm(AForm &AForm);
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& Bureaucrat);

#endif

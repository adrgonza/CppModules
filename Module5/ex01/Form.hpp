#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _sign;
		const int _gradeToExecute;
		const int _gradeToSign;
	public:
		Form();
		Form(std::string name);
		Form(const std::string name, const int gradeExec, const int gradeSign);
		Form(const Form & other);

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

		class FormAlredySigned : public std::exception
		{
			public:
				const char * what() const throw();
		};

		~Form();

		Form& operator=( const Form &other );

		std::string getName() const;
		int getGradeSign() const;
		int getGradeExec() const;
		bool getSign() const;
		void beSigned(Bureaucrat &Bureaucrat);
};

std::ostream& operator<<(std::ostream& os, Form& Form);

#endif

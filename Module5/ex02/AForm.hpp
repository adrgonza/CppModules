#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _sign;
		const int _gradeToExecute;
		const int _gradeToSign;
	public:
		AForm();
		AForm(std::string name);
		AForm(const std::string name, const int gradeExec, const int gradeSign);
		AForm(const AForm & other);

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

		class AFormAlredySigned : public std::exception
		{
			public:
				const char * what() const throw();
		};

		class AFormNotSigned : public std::exception
		{
			public:
				const char * what() const throw();
		};

		~AForm();

		AForm& operator=( const AForm &other );

		std::string getName() const;
		int getGradeSign() const;
		int getGradeExec() const;
		bool getSign() const;
		void beSigned(Bureaucrat &Bureaucrat);
		virtual void execute(Bureaucrat const& executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, AForm& AForm);

#endif

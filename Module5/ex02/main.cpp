#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

//chaange mateos grade to test de program

int main()
{
	Bureaucrat mateo("Mateo Pizzolo", 144);
	std::cout << mateo << std::endl;

	std::cout << "---------------------" << std::endl;

	ShrubberyCreationForm* form1 = new ShrubberyCreationForm("Shrubbery");
	if (!form1)
		return (1);
	std::cout << *form1 << std::endl;

	mateo.signAForm(*form1);
	mateo.execute(*form1);
	std::cout << std::endl;
	system("cat Shrubbery_shrubbery");
	std::cout << std::endl;
	delete form1;

	std::cout << "---------------------" << std::endl;

	RobotomyRequestForm* form2 = new RobotomyRequestForm("Robotomy");
	if (!form2)
		return (1);
	std::cout << *form2 << std::endl;
	mateo.signAForm(*form2);
	mateo.execute(*form2);
	std::cout << std::endl;
	delete form2;

	std::cout << "---------------------" << std::endl;

	PresidentialPardonForm* form3 = new PresidentialPardonForm("Presidential");
	if (!form3)
		return (1);
	std::cout << *form3 << std::endl;
	mateo.signAForm(*form3);
	mateo.execute(*form3);
	std::cout << std::endl;
	delete form3;
}

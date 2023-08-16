#include "Bureaucrat.hpp"
#include "Intern.hpp"

//change mateos grade to test de program

int main()
{
	Intern m;

	std::cout << m.makeForm("hola", "adios") << std::endl;

	Bureaucrat mateo("Mateo Pizzolo", 1);
	std::cout << mateo << std::endl;

	std::cout << "---------------------" << std::endl;

	AForm* form1 = m.makeForm("shrubbery creation", "Shrubbery");
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

	AForm* form2 = m.makeForm("robotomy request", "Robotomy");
	if (!form2)
		return (1);
	std::cout << *form2 << std::endl;
	mateo.signAForm(*form2);
	mateo.execute(*form2);
	std::cout << std::endl;
	delete form2;

	std::cout << "---------------------" << std::endl;

	AForm* form3 = m.makeForm("presidential pardon", "Pardon");
	if (!form3)
		return (1);
	std::cout << *form3 << std::endl;
	mateo.signAForm(*form3);
	mateo.execute(*form3);
	std::cout << std::endl;
	delete form3;
}

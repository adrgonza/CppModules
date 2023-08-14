#include "Bureaucrat.hpp"

int main()
{
	//Form formo("Formo", 13, 9);
	//std::cout << formo << std::endl;

	Bureaucrat mateo("mateo", 8);
	std::cout << mateo << std::endl;

	//mateo.signForm(formo);
    std::cout << "------------------------------" << std::endl;
	try
	{
		Bureaucrat low("low", 2);
		std::cout << low;
		low.incrementGrade();
		std::cout << low << std::endl;
		low.incrementGrade();
		std::cout << low << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
    std::cout << "------------------------------" << std::endl;
	Bureaucrat high("high", 149);
	try
	{
		std::cout << high << std::endl;
		high.decrementGrade();
		std::cout << high << std::endl;
        high.decrementGrade();
        std::cout << high << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

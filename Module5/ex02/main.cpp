#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat mateo("mateo", 10);
		std::cout << mateo << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
    std::cout << "------------------------------" << std::endl;
	try
	{
		Bureaucrat low("low", 2);
		std::cout << low;
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
    std::cout << "------------------------------" << std::endl;
	try
	{
		AForm a("other", 1150, 100);
		std::cout << a;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
    std::cout << "------------------------------" << std::endl;
    try
	{
        AForm a("a", 10, 20);
        high.signAForm(a);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
    std::cout << "------------------------------" << std::endl;
}

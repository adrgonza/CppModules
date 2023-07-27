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
		Form a("other", 1150, 100);
		std::cout << a;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
    std::cout << "------------------------------" << std::endl;
    try
	{
        Form a("a", 10, 20);
        high.signForm(a);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
    std::cout << "------------------------------" << std::endl;
}

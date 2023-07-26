#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat mateo("mateo", 2);
		std::cout << mateo << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat low("low", 1);
		std::cout << low;
		low.incrementGrade();
		std::cout << low << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat high("high", 150);
		std::cout << high << std::endl;
		high.decrementGrade();
		std::cout << high << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat a("other", 1150);
		std::cout << a;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}


	return 0;
}

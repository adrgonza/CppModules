#include "my_diary.hpp"

void	searchContact()
{

}

void	addContact()
{
	std::string input;

	std::cout << "First name: " << std::endl;
	std::getline(std::cin, input);

	std::cout << "Last name: " << std::endl;
	std::getline(std::cin, input);

	std::cout << "Nickname: " << std::endl;
	std::getline(std::cin, input);

	std::cout << "Phone number: " << std::endl;
	std::getline(std::cin, input);

	std::cout << "Darkest secret: " << std::endl;
	std::getline(std::cin, input);

	std::cout << std::endl << "Contact added..."<< std::endl << std::endl;

	std::cout << "COMAND LIST = |ADD| |SEARCH| |EXIT|" << std::endl;
}

int	main(void)
{
	std::string input;

	std::cout << "COMAND LIST == |ADD| |SEARCH| |EXIT|" << std::endl;
	while(true)
	{
		std::getline(std::cin, input);

		if (input == "ADD")
			addContact();

		if (input == "SEARCH")
			searchContact();

		if (input == "EXIT")
			return (0);
	}
}

#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook phone;
	std::string input;

	std::cout << "Comand list:" << std::endl << "'ADD'" << std::endl << "'SEARCH'" << std::endl << "'EXIT'" << std::endl;
	while(true)
	{
		std::getline(std::cin, input);

		if (input == "ADD")
			phone.addContact();

		if (input == "SEARCH")
			phone.searchContact();

		if (std::cin.eof() || input == "EXIT")
			return (0);
	}
}

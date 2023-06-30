#include "PhoneBook.hpp"

int PhoneBook::count = 0;

PhoneBook::PhoneBook() {}

PhoneBook::~PhoneBook() {}

void	PhoneBook::searchContact()
{
	std::string input;

	std::cout << std::endl << "|     index| firstname|  lastname|  nickname|" << std::endl;

	for (int i = 0; i < 8; i++)
	{
		std::cout << "|         " << i + 1
			<< "|" << std::setw(10) << std::right << this->contacts[i].getFirstName()
			<< "|" << std::setw(10) << std::right << this->contacts[i].getLastName()
			<< "|" << std::setw(10) << std::right << this->contacts[i].getNickName() << "|";
		std::cout << std::endl;
	}

	std::cout << "Insert a number to display contact info" << std::endl;

	while (true)
	{
		std::getline(std::cin, input);
		if (input == "1")
		{
			std::cout << "Comand list:" << std::endl << "'ADD'" << std::endl << "'SEARCH'" << std::endl << "'EXIT'" << std::endl;
			break ;
		}
		if (std::cin.eof())
			break ;
		else
			std::cout << "Invalid Contact" << std::endl;
	}
}

void	PhoneBook::addContact()
{
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	std::cout << "First name: " << std::endl;
	std::getline(std::cin, firstName);

	std::cout << "Last name: " << std::endl;
	std::getline(std::cin, lastName);

	std::cout << "Nickname: " << std::endl;
	std::getline(std::cin, nickname);

	std::cout << "Phone number: " << std::endl;
	std::getline(std::cin, phoneNumber);

	std::cout << "Darkest secret: " << std::endl;
	std::getline(std::cin, darkestSecret);

	count = count % 8;
	Contact add(firstName, lastName, nickname, phoneNumber, darkestSecret);
	this->contacts[count] = add;
	count++;

	std::cout << std::endl << "Contact added..."<< std::endl << std::endl;

	std::cout << "COMAND LIST = |ADD| |SEARCH| |EXIT|" << std::endl;
}

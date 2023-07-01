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
			<< "|" << std::setw(10) << std::right << this->contacts[i].getTruncFirstName()
			<< "|" << std::setw(10) << std::right << this->contacts[i].getTruncLastName()
			<< "|" << std::setw(10) << std::right << this->contacts[i].getTruncNickName() << "|";
		std::cout << std::endl;
	}

	std::cout << "Insert a number to display contact info" << std::endl;

	while (true)
	{
		std::getline(std::cin, input);
		if (std::cin.eof())
			break ;

		int number = atoi(input.c_str());

		if (number > 0 && number < 9)
		{
			std::cout << std::endl;
			std::cout << "First name: " << this->contacts[number - 1].getFirstName() << std::endl;
			std::cout << "Last name: " << this->contacts[number - 1].getLastName() << std::endl;
			std::cout << "Nickname: " << this->contacts[number - 1].getNickName() << std::endl;
			std::cout << "Phone Number: " << this->contacts[number - 1].getPhoneNumber() << std::endl;
			std::cout << "Darkest secret: " << this->contacts[number - 1].getDarkestSecret() << std::endl;

			std::cout << std::endl << "Comand list:" << std::endl << "'ADD'" << std::endl << "'SEARCH'" << std::endl << "'EXIT'" << std::endl;
			break ;
		}
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
	if (std::cin.eof())
		return ;

	std::cout << "Last name: " << std::endl;
	std::getline(std::cin, lastName);
	if (std::cin.eof())
		return ;

	std::cout << "Nickname: " << std::endl;
	std::getline(std::cin, nickname);
	if (std::cin.eof())
		return ;

	std::cout << "Phone number: " << std::endl;
	std::getline(std::cin, phoneNumber);
	if (std::cin.eof())
		return ;

	std::cout << "Darkest secret: " << std::endl;
	std::getline(std::cin, darkestSecret);
	if (std::cin.eof())
		return ;

	count = count % 8;
	Contact add(firstName, lastName, nickname, phoneNumber, darkestSecret);
	this->contacts[count] = add;
	count++;

	std::cout << std::endl << "Contact added..."<< std::endl << std::endl;

	std::cout << "COMAND LIST = |ADD| |SEARCH| |EXIT|" << std::endl;
}

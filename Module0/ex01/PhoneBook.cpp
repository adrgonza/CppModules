#include "PhoneBook.hpp"

int PhoneBook::count = 0;

PhoneBook::PhoneBook() {}

PhoneBook::~PhoneBook() {}

void	PhoneBook::searchContact()
{
	std::string input;

	if (this->contacts[0].getFirstName().empty())
	{
		std::cout << "\033[41mError : Add your first contact.\033[0m" << std::endl << std::endl;
		return ;
	}

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

		if (number > 0 && number < 9 && !this->contacts[number - 1].getFirstName().empty())
		{
			std::cout << std::endl;
			std::cout << "\033[47mFirst name     :\033[0m " << this->contacts[number - 1].getFirstName() << std::endl;
			std::cout << "\033[47mLast name      :\033[0m " << this->contacts[number - 1].getLastName() << std::endl;
			std::cout << "\033[47mNickname       :\033[0m " << this->contacts[number - 1].getNickName() << std::endl;
			std::cout << "\033[47mPhone Number   :\033[0m " << this->contacts[number - 1].getPhoneNumber() << std::endl;
			std::cout << "\033[47mDarkest secret :\033[0m " << this->contacts[number - 1].getDarkestSecret() << std::endl << std::endl;
			break ;
		}
		else
		{
			std::cout << "\033[41mError : Invalid Contact.\033[0m" << std::endl << std::endl;
			return ;
		}
	}
}

void	PhoneBook::addContact()
{
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	std::cout << std::endl << "First name: " << std::endl;
	std::getline(std::cin, firstName);
	if (firstName.empty())
	{
		std::cout << "\033[41mError : Invalid Imput.\033[0m" << std::endl << std::endl;;
		return ;
	}

	std::cout << "Last name: " << std::endl;
	std::getline(std::cin, lastName);
	if (lastName.empty())
	{
		std::cout << "\033[41mError : Invalid Imput.\033[0m" << std::endl << std::endl;;
		return ;
	}

	std::cout << "Nickname: " << std::endl;
	std::getline(std::cin, nickname);
	if (nickname.empty())
	{
		std::cout << "\033[41mError : Invalid Imput.\033[0m" << std::endl << std::endl;;
		return ;
	}

	std::cout << "Phone number: " << std::endl;
	std::getline(std::cin, phoneNumber);
	if (phoneNumber.empty())
	{
		std::cout << "\033[41mError : Invalid Imput.\033[0m" << std::endl << std::endl;;
		return ;
	}

	std::cout << "Darkest secret: " << std::endl;
	std::getline(std::cin, darkestSecret);
	if (darkestSecret.empty())
	{
		std::cout << "\033[41mError : Invalid Imput.\033[0m" << std::endl << std::endl;;
		return ;
	}

	count = count % 8;
	Contact add(firstName, lastName, nickname, phoneNumber, darkestSecret);
	this->contacts[count] = add;
	count++;

	std::cout << std::endl << "\033[42mContact added...\033[0m"<< std::endl << std::endl;
}

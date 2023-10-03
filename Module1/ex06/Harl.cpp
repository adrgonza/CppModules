
#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-picklespecial-ketchup burger. I really do!" << std::endl << std::endl;
}

void Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl << "I’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;
}
void Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

void Harl::defaultMsg( void )
{
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void Harl::complain( std::string level )
{
	int pos = 0;
	std::string status[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	while (pos < 4 && status[pos] != level)
		pos++;
	if (pos == 3 && status[pos] != "ERROR")
		pos++;

	switch (pos)
	{
		case 0:
			debug();
		case 1:
			info();
		case 2:
			warning();
		case 3:
			error(); break ;
		default:
			defaultMsg();
	}
	// void (Harl::*functionsArray[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	// for (int i = 0; i <= pos; i++)
	// 	(this->*functionsArray[i])();
}

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(std::string name)
{
	this->filename = name;

	std::ifstream inputFile(name);
	if (!inputFile)
	{
		std::cout << "Could not open the file..." << std::endl;
	}
}

BitcoinExchange::~BitcoinExchange()
{

}

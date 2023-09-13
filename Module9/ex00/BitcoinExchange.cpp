#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange::BitcoinExchange(std::string name)
{
	this->_filename = name;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		this->_exchangeRates = other._exchangeRates;
		this->_filename = other._filename;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{

}

void BitcoinExchange::calculateAndDisplayOutputs(const std::string date, const float fvalue)
{
	std::map<std::string, double>::iterator nearestExchangeRateIt = _exchangeRates.lower_bound(date);
	if (date != nearestExchangeRateIt->first)
		--nearestExchangeRateIt;

	double exchangeRate = nearestExchangeRateIt->second;
	double output = fvalue * exchangeRate;

	std::cout << date << " => " << fvalue << " = " << output << std::endl;
}

bool BitcoinExchange::parseDataBase(std::ifstream &dataBase)
{
	std::string line;
	std::getline(dataBase, line);
	while (std::getline(dataBase, line))
	{
		if (line.find(",") != 10)
		{
			std::cerr << "Error: invalid data base => " << line <<std::endl;
			return (false);
		}
		std::string date = line.substr(0, 10);
		std::string value = line.substr(11, line.length());
		if (!checkParams(date, value))
			return (false);

		double fvalue = std::atof(value.c_str());
		if (fvalue > 2147483647)
		{
			std::cout << "Error: number to large in database file " << value << std::endl;
			return (false);
		}
		this->_exchangeRates[date] = fvalue;
	}
	return (true);
}

bool BitcoinExchange::checkParams(const std::string date, const std::string value)
{
	for (int i = 0; i < 9; i++)
	{
		if ((i != 4 && i != 7) && !std::isdigit(date[i]))
		{
			std::cout << "Error: bad date => " << date << std::endl;
			return (false);
		}
		else if ((i == 4 || i == 7) && date[i] != '-')
		{
			std::cout << "Error: bad date => " << date << std::endl;
			return (false);
		}
	}

	int PointCount = 0;
	for (size_t i = 0; i < value.length(); i++)
	{
		if (value[i] == '.')
			PointCount++;
		if (i == 0 && value[0] == '-')
		{
			std::cout << "Error: not a positive number => " << value << std::endl;
			return (false);
		}
		if (value[i] != '.' && !std::isdigit(value[i]))
		{
			std::cout << "Error: invalid value => " << value << std::endl;
			return (false);
		}
	}
	if (PointCount > 1)
	{
		std::cout << "Error: invalid value => " << value << std::endl;
		return (false);
	}
	if (value.length() > 11)
	{
		std::cout << "Error: number to large => " << value << std::endl;
		return (false);
	}
	return (true);
}

bool BitcoinExchange::exec()
{
	std::ifstream dataBase("data.csv");
	if (!dataBase)
	{
		std::cerr << "Error: could not open DataBase." << std::endl;
		return (false);
	}

	if (parseDataBase(dataBase) == false)
	{
		dataBase.close();
		return (false);
	}

	std::ifstream file(_filename.c_str());
	if (!file)
	{
		std::cerr << "Error: could not open file input." << std::endl;
		return (false);
	}

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		if (line.find("|") != 11)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = line.substr(0, 10);
		std::string value = line.substr(13, line.length());
		if (!checkParams(date, value))
			continue;

		double fvalue = std::atof(value.c_str());
		if (fvalue > 2147483647)
		{
			std::cout << "Error: number too large => " << value << std::endl;
			continue;
		}
		calculateAndDisplayOutputs(date, fvalue);
	}
	return (true);
}

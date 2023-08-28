#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <map>

class BitcoinExchange
{
	private:
		std::string _filename;
		std::map<std::string, double> _exchangeRates;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange(std::string name);

		BitcoinExchange &operator=(const BitcoinExchange &other);

		~BitcoinExchange();

		void calculateAndDisplayOutputs(const std::string date, const float value);
		bool parseDataBase(std::ifstream &dataBase);
		bool checkParams(const std::string date, const std::string value);
		bool exec();
};

#endif

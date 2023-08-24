#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <map>

class BitcoinExchange
{
	private:
		std::string filename;
		std::ifstream file;
	public:
		BitcoinExchange();
		BitcoinExchange(std::string name);

		~BitcoinExchange();
};

#endif

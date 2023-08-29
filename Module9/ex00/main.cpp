#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Input file required.." << std::endl;
		return (1);
	}

	BitcoinExchange btc = BitcoinExchange(argv[1]);

	if (btc.exec() == false)
		return (1);

	return(0);
}
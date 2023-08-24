#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return ("Error... need a file imput", 0);

	std::ifstream inputFile(argv[1]);
	if (!inputFile)
		return (std::cout << "Could not open the file..." << std::endl, 1);

	std::map<int, std::string> file;
	std::string line;

	for (int i = 0; std::getline(inputFile, line); i++)
	{
		file[i] = line;
	}

	inputFile.close();


}

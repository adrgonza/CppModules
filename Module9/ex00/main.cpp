#include <iostream>
#include <string>
#include <fstream>
#include <map>

int main(int argc, char **argv)
{
	if (argc != 2 || argv[1] != "cpp_09.tgz")
		return ("Error: could not open file.", 0);

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

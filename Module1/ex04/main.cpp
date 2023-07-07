#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>

int main(int argc, char **argv)
{
	if (argc != 4)
		return (0);

	std::ifstream ifs;
	ifs.open(argv[1], std::ifstream::in);
	if (!ifs)
		return (1);

	std::ofstream ofs((std::string)argv[1] + ".replace");
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::string buffer;

	while (std::getline(ifs, buffer))
	{
		int pos = buffer.find(s1);
		while (pos != (int)std::string::npos)
		{
			buffer = buffer.substr(0, pos) + s2 + buffer.substr(pos + s1.length());
			pos = buffer.find(s1, pos + s2.length());
		}
		ofs << buffer << std::endl;
	}

	ifs.close();
	ofs.close();

	return (0);
}

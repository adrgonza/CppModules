#include "NumManage.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cout << "Invalid Arguments" << std::endl, 1);

	return (NumManage((std::string)argv[1]), 0);
}

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: only one arugument required.." << std::endl;
		return (1);
	}

	RPN rpn = RPN();

	if (!rpn.parseInput(argv[1]))
		return (1);

	if (!rpn.exec(argv[1]))
		return (1);

	return (0);
}

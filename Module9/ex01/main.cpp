#include "RPN.hpp"

int main(int argc, char **argv)
{
  	if (argc != 2)
	{
		std::cerr << "Error: program need an argument." << std::endl;
		return (1);
	}

    RPN rpn = RPN();

    if (!rpn.parseInput(argv[1]))
    {
        return (1);
    }
    
    if (!rpn.exec(argv[1]))
    {
        return (1);
    }

    return (0);
}
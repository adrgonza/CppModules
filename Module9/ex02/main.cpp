#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        std::cerr << "Error: not enought arguments.." << std::endl;
        return (1);
    }

    PmergeMe merge = PmergeMe(argc);

    if (!merge.parseArgument(argv))
        return (1);
    
    merge.exec();
}
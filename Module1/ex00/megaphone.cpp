#include <string>
#include <iostream>

int	main(int argc, char **argv)
{
	int i = 0;

	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (argv && argv[++i])
	{
		int j = -1;
		while(argv && argv[i][++j])
			std::cout << (char)toupper(argv[i][j]);
	}
	std::cout << std::endl;
	return (0);
}

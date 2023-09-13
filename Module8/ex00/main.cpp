
#include "easyfind.hpp"

int main()
{
	int nb = 20;
	std::vector<int> vect;

	for (int i = 0; i < nb; i++)
	{
		vect.push_back(i + 100);
	}
	for (int i = 0; i < nb; i++)
	{
		std::cout << vect[i] << std::endl;
	}

	try
	{
		std::vector<int>::iterator result;

		result = easyfind(vect, 100002);

		std::cout << "Value found at index: " << std::distance(vect.begin(), result) << std::endl;
	}
	catch (const std::out_of_range& e)
	{
		std::cout << e.what() << std::endl;
	}

}


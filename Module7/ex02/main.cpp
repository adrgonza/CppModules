#include <iostream>
#include "Array.hpp"


int main()
{
	Array<char> a;
	Array<char> ab(120);
	Array<char> abc(ab);

	std::cout << a.size() << std::endl;
	std::cout << ab.size() << std::endl;
	std::cout << abc.size() << std::endl;

	a = abc;

	std::cout << a.size() << std::endl;

	for (int i = 0; i < 120; i++)
	{
		a[i] = 'a';
	}
	ab = a;
	abc = ab;

	for (int i = 0; i < 120; i++)
	{
		std::cout << a[i];
	}
	std::cout << std::endl;
	for (int i = 0; i < 120; i++)
	{
		std::cout << ab[i];
	}
	std::cout << std::endl;
	for (int i = 0; i < 120; i++)
	{
		std::cout << abc[i];
	}
	std::cout << std::endl;
}





// #define MAX_VAL 2000
// int main(int, char**)
// {
// 	Array<int> numbers(MAX_VAL);
// 	int* mirror = new int[MAX_VAL];
// 	srand(time(NULL));
// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		const int value = rand();
// 		numbers[i] = value;
// 		mirror[i] = value;
// 	}
// 	//SCOPE
// 	{
// 		Array<int> tmp = numbers;
// 		Array<int> test(tmp);
// 	}

// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		if (mirror[i] != numbers[i])
// 		{
// 			std::cerr << "didn't save the same value!!" << std::endl;
// 			return 1;
// 		}
// 	}
// 	try
// 	{
// 		numbers[-2] = 0;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	try
// 	{
// 		numbers[MAX_VAL] = 0;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		numbers[i] = rand();
// 	}
// 	delete [] mirror;//
// 	return 0;
// }

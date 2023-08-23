#include "iter.hpp"

template<typename T>
void printElement(T &c)
{
	std::cout << c << " ";
}

int main()
{
	char array[10] = {"hola que"};
	int enteros[] = {1, 2 ,3, 4, 5};
	float decimales[]= {1.3f, 32.90432f, 2.423f, 432.943f};

	::iter(array, 10, printElement<char>);
	std::cout << std::endl;
	::iter(enteros, 5, printElement<int>);
	std::cout << std::endl;
	::iter(decimales, 4, printElement<float>);
	std::cout << std::endl;

}

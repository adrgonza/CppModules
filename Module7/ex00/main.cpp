#include "whatever.hpp"

int main()
{
	int a = 1;
	int aa = 2;

	float b = 1.8f;
	float bb = 1.3;

	double c = 1.7f;
	double cc = 2.7f;

	char d = 'a';
	char dd = 'p';

	std::cout << "a = " << a << std::endl << "aa = " << aa << std::endl;
	::swap(a, aa);
	std::cout << "a = " << a << std::endl << "aa = " << aa << std::endl;


	std::cout << "b = " << b << std::endl << "bb = " << bb << std::endl;
	::swap(b, bb);
	std::cout << "b = " << b << std::endl << "bb = " << bb << std::endl;


	std::cout << "c = " << c << std::endl << "cc = " << cc << std::endl;
	::swap(c, cc);
	std::cout << "c = " << c << std::endl << "cc = " << cc << std::endl;


	std::cout << "d = " << d << std::endl << "dd = " << dd << std::endl;
	::swap(d, dd);
	std::cout << "d = " << d << std::endl << "dd = " << dd << std::endl;

	std::cout << "int max =  " << ::max(aa, a) << std::endl << "int min = " << ::min(a, aa) << std::endl;

	std::cout << "float max =  " << ::max(b, bb) << std::endl << "float min = " << ::min(b, bb) << std::endl;

	std::cout << "double max =  " << ::max(c, cc) << std::endl << "double min = " << ::min(c, cc) << std::endl;

	std::cout << "char max =  " << ::max(d, dd) << std::endl << "char min = " << ::min(d, dd) << std::endl;
}
